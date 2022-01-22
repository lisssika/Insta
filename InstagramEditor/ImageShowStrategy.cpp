#include "ImageShowStrategy.h"
#include <opencv2/highgui.hpp>
#include <stdexcept>

cv::Mat InstagramShow::show(const cv::Mat& image, const std::string& window_name)
{
	const int window_height = cv::getWindowImageRect(window_name).height;
	const int window_width = cv::getWindowImageRect(window_name).width;
	if (window_width!=window_height)
	{
		throw std::runtime_error("This window is not square");
	}
}
