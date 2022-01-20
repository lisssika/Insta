#pragma once
#include <opencv2/core/mat.hpp>

class ImageTransformer
{
public:
	virtual cv::Mat transform(const cv::Mat& image) = 0;

};

