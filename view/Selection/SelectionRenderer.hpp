#pragma once

#include "SelectionModel.hpp"
#include "img.hpp"
/*
 * @class SelectionRenderer
 * @brief Responsible for rendering selection markers on the board.
 * Purpose: Draws the selected tile and all legal target moves for the piece.
 * Created by: Renderer | Used by: Renderer on each refresh.
 * Functions: draw() (draws selection markers and legal moves on canvas).
 */
class SelectionRenderer
{
private:

    static constexpr int CELL_SIZE = 100;

public:

    void draw(
        const SelectionModel& selection,
        Img& canvas);
};