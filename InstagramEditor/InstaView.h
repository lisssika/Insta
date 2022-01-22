#pragma once
#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include "ImageShowStrategy.h"
#include "ImageResizer.h"


class InstaView final : public ImageShowStrategy
{
public:
	cv::Mat show(const cv::Mat& image, const std::string& window_name) override;
private:
	ImageProportionalResizer resizer_;
};