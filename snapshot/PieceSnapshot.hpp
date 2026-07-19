#pragma once

#include "Piece.hpp"
#include "Position.hpp"
/*
 * @struct PieceSnapshot
 * @brief מייצג צילום מצב של כלי בודד לצורך ציורו על המסך.
 * מטרה: שמירת נתונים גרפיים של כלי מסוים ללא גישה ישירה לאובייקט ה-Piece במודל.
 * מכיל: זהות הכלי, סוג וצבע, מצב אנימציה, מיקום בלוח, ונתוני תנועה לצורך החלקה.
 * יוצר: GameEngine::snapshot().
 * משתמשים: PieceRenderer.
 */
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
