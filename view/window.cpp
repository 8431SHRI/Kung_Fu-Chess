#include "Window.hpp"

#include <opencv2/highgui.hpp>

Window *Window::instance = nullptr;

Window::Window(
    Renderer &r,
    GameController &c,
    SelectionModel &s)
    : renderer(r),
      controller(c),
      selection(s)
{
    instance = this;

    canvas.read(
        "assets/board.png",
        {800, 800},
        false);

    if (canvas.get_mat().channels() == 3)
    {
        cv::cvtColor(
            canvas.get_mat(),
            canvas.get_mat(),
            cv::COLOR_BGR2BGRA);
    }

    cv::namedWindow("Kung Fu Chess");

    cv::setMouseCallback(
        "Kung Fu Chess",
        Window::mouseCallback,
        nullptr);
}

void Window::mouseCallback(
    int event,
    int x,
    int y,
    int,
    void *)
{
    
    if (event != cv::EVENT_LBUTTONDOWN)
        return;

    if (instance == nullptr)
        return;

    instance->controller.click(x, y);
}

void Window::render(
    const GameSnapshot &snapshot)
{
    canvas.read(
        "assets/board.png",
        {800, 800},
        false);

    if (canvas.get_mat().channels() == 3)
    {
        cv::cvtColor(
            canvas.get_mat(),
            canvas.get_mat(),
            cv::COLOR_BGR2BGRA);
    }

    renderer.render(
        snapshot,
        selection,
        canvas);
}

void Window::show()
{
    cv::imshow(
        "Kung Fu Chess",
        canvas.get_mat());
}

Img &Window::getCanvas()
{
    return canvas;
}