#pragma once

#include <vector>
#include "PieceSnapshot.hpp"

struct GameSnapshot
{
    int rows;

    int cols;

    bool gameOver;

    std::vector<PieceSnapshot> pieces;

    bool hasSelection;

    Position selectedCell;

    std::vector<Position> legalMoves;
};