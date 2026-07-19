#include "PieceRenderer.hpp"

PieceRenderer::PieceRenderer(ResourceManager &resourceManager)
    : resources(resourceManager)
{
}

void PieceRenderer::drawPiece(
    const PieceSnapshot &piece,
    Img &canvas,
    int elapsedMs)
{
    Animation &animation =
        resources.getAnimation(
            piece.type,
            piece.side,
            piece.state,
            CELL_SIZE);

    std::shared_ptr<Img> image =
        animation.getFrameByTime(elapsedMs);

    double x;
    double y;

    if (piece.isMoving)
    {
        double startX =
            piece.motionSource.getCol() * CELL_SIZE;

        double startY =
            piece.motionSource.getRow() * CELL_SIZE;

        double endX =
            piece.motionDestination.getCol() * CELL_SIZE;

        double endY =
            piece.motionDestination.getRow() * CELL_SIZE;

        x =
            startX +
            (endX - startX) * piece.progress;

        y =
            startY +
            (endY - startY) * piece.progress;
    }
    else
    {
        x =
            piece.boardPosition.getCol() * CELL_SIZE;

        y =
            piece.boardPosition.getRow() * CELL_SIZE;
    }

    image->draw_transparent(
        canvas.get_mat(),
        static_cast<int>(x),
        static_cast<int>(y));
}