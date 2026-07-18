#include "SelectionRenderer.hpp"

#include <opencv2/imgproc.hpp>

void SelectionRenderer::draw(
    const SelectionModel &selection,
    Img &canvas)
{
    cv::Mat &image =
        const_cast<cv::Mat &>(canvas.get_mat());

    //
    // ציור המשבצת שנבחרה
    //

    if (selection.hasSelection())
    {
        const Position &pos =
            selection.getSelection().value();

        int x = pos.getCol() * CELL_SIZE;

        int y = pos.getRow() * CELL_SIZE;

        cv::rectangle(
            image,
            cv::Rect(
                x,
                y,
                CELL_SIZE,
                CELL_SIZE),
            cv::Scalar(0, 255, 255, 255),
            3);
    }

    //
    // ציור כל היעדים החוקיים
    //

    for (const Position &pos : selection.getLegalMoves())
    {
        int centerX =
            pos.getCol() * CELL_SIZE +
            CELL_SIZE / 2;

        int centerY =
            pos.getRow() * CELL_SIZE +
            CELL_SIZE / 2;

        cv::rectangle(
            image,
            cv::Rect(
                pos.getCol() * CELL_SIZE,
                pos.getRow() * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE),
            cv::Scalar(0, 220, 0, 255),
            2);
    }
}