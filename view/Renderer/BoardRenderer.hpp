#pragma once

#include <string>

#include "img.hpp"
/*
 * @class BoardRenderer
 * @brief Responsible for rendering the chessboard image onto the canvas.
 * Purpose: Loads the board image once and draws it on every screen refresh.
 * Created by: Renderer | Used by: Renderer on every render cycle.
 * Functions: BoardRenderer() (load from disk), drawBoard() (draw on canvas).
 */
class BoardRenderer
{
private:

    Img boardImage;

public:

    explicit BoardRenderer(const std::string& boardPath);

    void drawBoard(Img& canvas);
};