#pragma once

#include "Piece.hpp"
#include "Position.hpp"

struct PieceSnapshot
{
    int id;

    Side side;

    PieceType type;

    PieceState state;

    Position boardPosition;

    bool isMoving = false;

    Position motionSource;
    
    Position motionDestination;

    double progress = 0.0;
};
