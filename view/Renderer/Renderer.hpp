#pragma once

#include <string>

#include "BoardRenderer.hpp"
#include "PieceRenderer.hpp"
#include "ResourceManager.hpp"
#include "GameSnapshot.hpp"
#include "SelectionRenderer.hpp"
/*
 * @class Renderer
 * @brief אחראי על ציור כל המסך של המשחק.
 * מטרה: ריכוז כל פעולות הציור: לוח, סימוני בחירה, כלים והודעות סיום.
 * יוצר: main() | משתמשים: Window בכל רענון מסך.
 * פונקציות: Renderer() (אתחול רכיבי ציור), render() (ציור כל מצב המשחק).
 */
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