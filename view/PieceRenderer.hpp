#pragma once

#include "ResourceManager.hpp"
#include "PieceSnapshot.hpp"
#include "Animation.hpp"
#include "img.hpp"

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