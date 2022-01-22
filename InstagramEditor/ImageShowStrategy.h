#pragma once
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <string>

class ImageShowStrategy
{
public:
	virtual cv::Mat show(const cv::Mat& image, const std::string& window_name) = 0;
	virtual ~ImageShowStrategy() = default;
};

