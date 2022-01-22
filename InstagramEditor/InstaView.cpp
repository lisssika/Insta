#include "InstaView.h"
#include <opencv2/core/mat.hpp>

cv::Mat InstaView::show(const cv::Mat& image, const std::string& window_name)
{
	const int window_height = cv::getWindowImageRect(window_name).height;
	const int window_width = cv::getWindowImageRect(window_name).width;
	if (window_width != window_height)
	{
		throw std::runtime_error("This window is not square");
	}
	const int window_size = window_height;
	double scale = window_size / image.rows;
	resizer_.set_parameters(scale, image); // а мб окошечко это всё само может сделать?
}