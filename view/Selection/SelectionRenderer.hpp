#pragma once

#include "SelectionModel.hpp"
#include "img.hpp"
/*
 * @class SelectionRenderer
 * @brief אחראי על ציור סימוני הבחירה על הלוח.
 * מטרה: ציור המשבצת שנבחרה וכל היעדים החוקיים של הכלי.
 * יוצר: Renderer | משתמשים: Renderer בכל רענון מסך.
 * פונקציות: draw() (ציור סימוני בחירה ומהלכים חוקיים על הקנבס).
 */
class SelectionRenderer
{
private:

    static constexpr int CELL_SIZE = 100;

public:

    void draw(
        const SelectionModel& selection,
        Img& canvas);
};