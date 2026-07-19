#pragma once

#include <string>

#include "img.hpp"
#include "Renderer.hpp"
#include "GameController.hpp"
#include "SelectionModel.hpp"
/*
 * @class Window
 * @brief Manages the game window and the render loop.
 * Purpose: Manages OpenCV window, handles mouse events, and displays the canvas.
 * Created by: main() | Used by: Main game loop.
 * Functions: Window() (initialization), render() (draw to screen), show() (display), getCanvas() (retrieve), mouseCallback() (input events).
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