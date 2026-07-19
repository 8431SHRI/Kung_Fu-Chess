#pragma once

#include <string>

#include "BoardRenderer.hpp"
#include "PieceRenderer.hpp"
#include "ResourceManager.hpp"
#include "GameSnapshot.hpp"
#include "SelectionRenderer.hpp"
class Renderer
{
private:
    BoardRenderer boardRenderer;
    SelectionRenderer selectionRenderer;
    PieceRenderer pieceRenderer;

public:
    Renderer(
        ResourceManager &resources,
        const std::string &boardPath);

    void render(
        const GameSnapshot &snapshot,
        const SelectionModel &selection,
        Img &canvas);
};