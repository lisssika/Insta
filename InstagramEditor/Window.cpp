#include "Window.h"
#include <opencv2/highgui.hpp>

Window::Window(const std::string& name, int width, int height)
{
	cv::namedWindow(name, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
	cv::resizeWindow(name, width, height);
}
