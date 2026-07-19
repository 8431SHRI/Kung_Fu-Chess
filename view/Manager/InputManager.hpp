#pragma once

#include "GameController.hpp"

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