// #include "Renderer.hpp"

// Renderer::Renderer(
//     ResourceManager& resources,
//     const std::string& boardPath)
//     :
//     boardRenderer(boardPath),
//     pieceRenderer(resources)
// {
// }

// void Renderer::render(
//     const GameSnapshot& snapshot,
//     Img& canvas,
//     int animationFrame)
// {
//     boardRenderer.drawBoard(canvas);

//     for (const PieceSnapshot& piece : snapshot.pieces)
//     {
//         pieceRenderer.drawPiece(
//             piece,
//             canvas,
//             animationFrame);
//     }
// }
#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(
    ResourceManager &resources,
    const std::string &boardPath)
    : boardRenderer(boardPath),
      pieceRenderer(resources)
{
}

void Renderer::render(
    const GameSnapshot &snapshot,
    const SelectionModel &selection,
    Img &canvas)
{

    boardRenderer.drawBoard(canvas);

    selectionRenderer.draw(
        selection,
        canvas);

    for (const auto &piece : snapshot.pieces)
    {
        pieceRenderer.drawPiece(
            piece,
            canvas);
    }

    if (snapshot.gameOver)
    {
        cv::rectangle(
            canvas.get_mat(),
            cv::Rect(0, 0, 800, 800),
            cv::Scalar(0, 0, 0, 170),
            -1);
        canvas.put_text(
            "GAME OVER",
            120,
            420,
            3.5,
            cv::Scalar(255, 255, 255, 255),
            6);
    }
}
