#include "ResourceManager.hpp"

#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

ResourceManager::ResourceManager(const std::string& assetsFolder)
    : assetsPath(assetsFolder)
{
}

std::string ResourceManager::pieceToString(PieceType type) const
{
    switch (type)
    {
    case PieceType::KING:   return "king";
    case PieceType::QUEEN:  return "queen";
    case PieceType::ROOK:   return "rook";
    case PieceType::BISHOP: return "bishop";
    case PieceType::KNIGHT: return "knight";
    case PieceType::PAWN:   return "pawn";
    }

    return "";
}

std::string ResourceManager::sideToString(Side side) const
{
    return side == Side::WHITE ? "white" : "black";
}

std::string ResourceManager::stateToString(PieceState state) const
{
    switch (state)
    {
    case PieceState::IDLE:
        return "idle";

    case PieceState::MOVING:
        return "move";

    case PieceState::AIRBORNE:
        return "jump";

    case PieceState::CAPTURED:
        return "captured";
    }

    return "idle";
}

std::string ResourceManager::buildFolder(
    PieceType type,
    Side side,
    PieceState state) const
{
    fs::path path = assetsPath;

    path /= "pieces";
    path /= sideToString(side);
    path /= pieceToString(type);
    path /= stateToString(state);
    path /= "sprites";

    return path.string();
}

std::string ResourceManager::buildKey(
    PieceType type,
    Side side,
    PieceState state,
    int size) const
{
    return
        pieceToString(type) + "_" +
        sideToString(side) + "_" +
        stateToString(state) + "_" +
        std::to_string(size);
}

Animation ResourceManager::loadAnimation(
    PieceType type,
    Side side,
    PieceState state,
    int size)
{
    Animation animation;

    fs::path folder = buildFolder(type, side, state);

    if (!fs::exists(folder))
    {
        throw std::runtime_error(
            "Animation folder not found: " +
            folder.string());
    }

    std::vector<fs::path> files;

    for (const auto& entry : fs::directory_iterator(folder))
    {
        if (entry.path().extension() == ".png")
        {
            files.push_back(entry.path());
        }
    }

    std::sort(files.begin(), files.end());
    loadAnimationMetadata(
    animation,
    folder);
    for (const auto& file : files)
    {
        auto image = std::make_shared<Img>();

        image->read(
            file.string(),
            { size, size },
            false);

        animation.addFrame(image);
    }

    return animation;
}

Animation& ResourceManager::getAnimation(
    PieceType type,
    Side side,
    PieceState state,
    int size)
{
    std::string key =
        buildKey(type, side, state, size);

    auto it = animationCache.find(key);

    if (it != animationCache.end())
    {
        return it->second;
    }

    animationCache[key] =
        loadAnimation(type, side, state, size);

    return animationCache[key];
}

void ResourceManager::loadAnimationMetadata(
    Animation& animation,
    const fs::path& folder)
{
    fs::path jsonFile = folder.parent_path() / "config.json";

    if (!fs::exists(jsonFile))
    {
        return;
    }

    std::ifstream file(jsonFile);

    json j;

    file >> j;

    if (j.contains("graphics"))
    {
        auto graphics = j["graphics"];

        if (graphics.contains("frames_per_sec"))
        {
            animation.setFramesPerSecond(
                graphics["frames_per_sec"]);
        }

        if (graphics.contains("is_loop"))
        {
            animation.setLoop(
                graphics["is_loop"]);
        }
    }
}