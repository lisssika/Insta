#pragma once
#include "ImageTransformer.h"
#include "Point.h"

class SqrImageCropper final:public  ImageTransformer
{
public:
	cv::Mat transform() override;
	void set_parameters(int size, const Point& left_up_point, const cv::Mat& image);
private:
	int size_{};
	Point left_up_point_{};
};
