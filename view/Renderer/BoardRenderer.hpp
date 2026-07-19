#pragma once

#include <string>

#include "img.hpp"
/*
 * @class BoardRenderer
 * @brief אחראי על ציור תמונת לוח השחמט על הקנבס.
 * מטרה: טעינת תמונת הלוח פעם אחת וציורה בכל רענון מסך.
 * יוצר: Renderer | משתמשים: Renderer בכל מחזור ציור.
 * פונקציות: BoardRenderer() (טעינה מהדיסק), drawBoard() (ציור על הקנבס).
 */
class BoardRenderer
{
private:

    Img boardImage;

public:

    explicit BoardRenderer(const std::string& boardPath);

    void drawBoard(Img& canvas);
};