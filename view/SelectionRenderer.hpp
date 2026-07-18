#pragma once

#include "SelectionModel.hpp"
#include "img.hpp"

class SelectionRenderer
{
private:

    static constexpr int CELL_SIZE = 100;

public:

    void draw(
        const SelectionModel& selection,
        Img& canvas);
};