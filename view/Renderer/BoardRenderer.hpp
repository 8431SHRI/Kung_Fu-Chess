#pragma once

#include <string>

#include "img.hpp"

class BoardRenderer
{
private:

    Img boardImage;

public:

    explicit BoardRenderer(const std::string& boardPath);

    void drawBoard(Img& canvas);
};