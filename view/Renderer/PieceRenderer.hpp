#pragma once

#include "ResourceManager.hpp"
#include "PieceSnapshot.hpp"
#include "Animation.hpp"
#include "img.hpp"
/*
 * @class PieceRenderer
 * @brief אחראי על ציור כלי משחק בודד והאנימציה שלו.
 * מטרה: בחירת אנימציה, חישוב מיקום וציור על הקנבס.
 * יוצר: Renderer | משתמשים: Renderer עבור כל כלי במשחק.
 * פונקציות: PieceRenderer() (אתחול עם ResourceManager), drawPiece() (ציור הכלי והפריים).
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