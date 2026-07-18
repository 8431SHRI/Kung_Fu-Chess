#include "BoardRenderer.hpp"

BoardRenderer::BoardRenderer(const std::string& boardPath)
{
    boardImage.read(
        boardPath,
        {800, 800},
        false);

    if (boardImage.get_mat().channels() == 3)
    {
        cv::cvtColor(
            boardImage.get_mat(),
            boardImage.get_mat(),
            cv::COLOR_BGR2BGRA);
    }
}

void BoardRenderer::drawBoard(Img& canvas)
{
    boardImage.get_mat().copyTo(
        canvas.get_mat());
}