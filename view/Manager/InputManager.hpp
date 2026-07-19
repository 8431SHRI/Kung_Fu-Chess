#pragma once

#include "GameController.hpp"
/*
 * @class InputManager
 * @brief אחראי על קליטת פעולות הקלט מהמשתמש והעברתן לבקר המשחק.
 * מטרה: הפרדת שכבת הקלט מלוגיקת המשחק; העברת אירועי עכבר ל-GameController.
 * יוצר: main() | משתמשים: Window (דרך mouseCallback).
 * פונקציות: InputManager() (אתחול), leftClick() (טיפול בלחיצה והעברתה לבקר).
 */
class InputManager
{
private:

    GameController& controller;

public:

    explicit InputManager(
        GameController& c);

    void leftClick(
        int x,
        int y);
};