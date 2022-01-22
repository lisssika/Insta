#pragma once
#include "ImageTransformer.h"
#include <opencv2/core/mat.hpp> 

class ImageProportionalResizer final :public  ImageTransformer
{
public:
	void set_parameters(double scale, const cv::Mat& image);
	cv::Mat transform() override;
private:
	double scale_{};
};
