#pragma once

#include <vector>
#include "PieceSnapshot.hpp"
/*
 * @struct GameSnapshot
 * @brief מייצג תמונת מצב מלאה של המשחק ברגע נתון.
 * מטרה: משמש להעברת המידע הדרוש ל-Renderer מבלי לתת לו גישה ישירה למנוע המשחק.
 * מכיל: גודל הלוח, רשימת הכלים ומצבם, סטטוס סיום משחק, כלי נבחר ומהלכיו החוקיים.
 * יוצר: GameEngine::snapshot().
 * משתמשים: Renderer, PieceRenderer, SelectionRenderer.
 */
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