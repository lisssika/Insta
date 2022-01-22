#pragma once
#include "ImageTransformer.h"
#include <opencv2/core/mat.hpp> 

class ImageProportionalResizer final :public  ImageTransformer
{
public:
	void set_parameters(double scale);
	cv::Mat transform(const cv::Mat& original_image) override;
private:
	double scale_{};
};
