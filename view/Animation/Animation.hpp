#pragma once

#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>

#include "img.hpp"

class Animation
{
private:

    std::vector<std::shared_ptr<Img>> frames;

    int framesPerSecond = 6;

    bool loop = true;

public:

    Animation() = default;

    void addFrame(std::shared_ptr<Img> frame)
    {
        frames.push_back(frame);
    }

    void setFramesPerSecond(int fps)
    {
        framesPerSecond = fps;
    }

    int getFramesPerSecond() const
    {
        return framesPerSecond;
    }

    void setLoop(bool value)
    {
        loop = value;
    }

    bool isLoop() const
    {
        return loop;
    }

    bool empty() const
    {
        return frames.empty();
    }

    int frameCount() const
    {
        return static_cast<int>(frames.size());
    }

    std::shared_ptr<Img> getFrame(int index)
    {
        if (frames.empty())
        {
            throw std::runtime_error("Animation contains no frames.");
        }

        if (index < 0)
        {
            index = 0;
        }

        index %= frames.size();

        return frames[index];
    }

    std::shared_ptr<Img> getFrameByTime(int elapsedMs)
    {
        if (frames.empty())
        {
            throw std::runtime_error("Animation contains no frames.");
        }

        int frame =
            (elapsedMs * framesPerSecond) / 1000;

        if (loop)
        {
            frame %= frames.size();
        }
        else
        {
            frame = std::min(
                frame,
                (int)frames.size() - 1);
        }

        return frames[frame];
    }

    const std::vector<std::shared_ptr<Img>>& getFrames() const
    {
        return frames;
    }
};