#pragma once
#include <opencv2/core/mat.hpp>

class ImageTransformer
{
public:
	virtual cv::Mat transform() = 0;
	virtual ~ImageTransformer() = default;
protected:
	cv::Mat original_image_;
};
