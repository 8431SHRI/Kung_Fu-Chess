#pragma once

#include <optional>
#include <set>
#include <vector>

#include "Position.hpp"
/*
 * @class SelectionModel
 * @brief שומר את מצב הבחירה הנוכחי של המשתמש.
 * מטרה: ניהול הכלי הנבחר והמהלכים החוקיים שלו לצורך תצוגה.
 * יוצר: main() | משתמשים: GameController (עדכון), SelectionRenderer/Window (קריאה).
 * פונקציות: clear() (ניקוי), select() (בחירה חדשה), hasSelection/getSelection() (שאילתה), set/getLegalMoves() (ניהול מהלכים).
 */
class SelectionModel
{
private:
    std::optional<Position> selectedSquare;

    std::set<Position> legalMoves;

public:
    SelectionModel() = default;

    void clear();

    void select(const Position &pos);

    bool hasSelection() const;

    const std::optional<Position> &getSelection() const;

    void setLegalMoves(const std::set<Position> &moves);

    const std::set<Position> &getLegalMoves() const;
};