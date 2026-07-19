#pragma once

#include "ResourceManager.hpp"
#include "PieceSnapshot.hpp"
#include "Animation.hpp"
#include "img.hpp"
/*
 * @class PieceRenderer
 * @brief Responsible for rendering an individual game piece and its animation.
 * Purpose: Selects animation, calculates position, and draws on the canvas.
 * Created by: Renderer | Used by: Renderer for each game piece.
 * Functions: PieceRenderer() (initialization with ResourceManager), drawPiece() (draws piece and current frame).
 */
class PieceRenderer
{
private:

    ResourceManager& resources;

    static constexpr int CELL_SIZE = 100;

public:

    explicit PieceRenderer(ResourceManager& resourceManager);

    void drawPiece(
    const PieceSnapshot& piece,
    Img& canvas,
    int elapsedMs);
};