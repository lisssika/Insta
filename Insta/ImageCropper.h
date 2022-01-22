#pragma once
#include "ImageTransformer.h"
#include "Point.h"

class ImageCropper final : public ImageTransformer
{
public:
	ImageCropper(int size, const Point& center);
	cv::Mat transform(const cv::Mat& original_image) override;
	void set_params(int size, Point center);
	void set_size(int size);
	void set_new_center(Point new_center);
private:
	int size_;
	Point center_;
	//bool calc_center_automatically_;
};

