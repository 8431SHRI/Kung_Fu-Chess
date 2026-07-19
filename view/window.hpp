#pragma once

#include <string>

#include "img.hpp"
#include "Renderer.hpp"
#include "GameController.hpp"
#include "SelectionModel.hpp"
/*
 * @class Window
 * @brief מנהל את חלון המשחק ואת מחזור הציור.
 * מטרה: ניהול חלון OpenCV, טיפול באירועי עכבר, והצגת הקנבס.
 * יוצר: main() | משתמשים: לולאת המשחק הראשית (main).
 * פונקציות: Window() (אתחול), render() (ציור למסך), show() (תצוגה), getCanvas() (שליפה), mouseCallback() (אירועי קלט).
 */
class Window
{
private:

    Img canvas;

    Renderer& renderer;
    SelectionModel& selection;
    GameController& controller;

    static Window* instance;

    static void mouseCallback(
        int event,
        int x,
        int y,
        int flags,
        void* userdata);

public:

    Window(
    Renderer& renderer,
    GameController& controller,
    SelectionModel& selection);

    void render(
        const GameSnapshot& snapshot);

    void show();

    Img& getCanvas();
};