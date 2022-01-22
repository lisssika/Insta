#pragma once
#include <opencv2/core/mat.hpp>

class ImageTransformer
{
public:
	virtual cv::Mat transform(const cv::Mat&) = 0;
	virtual ~ImageTransformer() = default;
};
