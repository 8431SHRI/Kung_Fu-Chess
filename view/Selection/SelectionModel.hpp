#pragma once

#include <optional>
#include <set>
#include <vector>

#include "Position.hpp"

class SelectionModel
{
private:
    std::optional<Position> selectedSquare;

    std::set<Position> legalMoves;

public:
    SelectionModel() = default;

    void clear();

    void select(const Position &pos);

    bool hasSelection() const;

    const std::optional<Position> &getSelection() const;

    void setLegalMoves(const std::set<Position> &moves);

    const std::set<Position> &getLegalMoves() const;
};