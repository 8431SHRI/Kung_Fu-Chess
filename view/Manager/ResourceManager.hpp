#pragma once

#include <map>
#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "Animation.hpp"
#include "Piece.hpp"
/*
 * @class Renderer
 * @brief Responsible for drawing the entire game screen.
 * Purpose: Centralizes all drawing operations: board, selection markers, pieces, and end-game messages.
 * Created by: main() | Used by: Window on each refresh.
 * Functions: Renderer() (initialization of drawing components), render() (draws current game state).
 */
class ResourceManager
{
private:

    std::string assetsPath;

    std::map<std::string, Animation> animationCache;

    std::string buildKey(
        PieceType type,
        Side side,
        PieceState state,
        int size) const;

    std::string pieceToString(PieceType type) const;

    std::string sideToString(Side side) const;

    std::string stateToString(PieceState state) const;

    std::string buildFolder(
        PieceType type,
        Side side,
        PieceState state) const;

    Animation loadAnimation(
        PieceType type,
        Side side,
        PieceState state,
        int size);

public:
    void loadAnimationMetadata(
    Animation& animation,
    const std::filesystem::path& folder);
    explicit ResourceManager(
        const std::string& assetsFolder);

    Animation& getAnimation(
        PieceType type,
        Side side,
        PieceState state,
        int size);
};