#include "ImageCropper.h"
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

// проверка на адекватность размера и выход за границы нужна
ImageCropper::ImageCropper(int size, const Point& center):size_(size), center_(center){}

cv::Mat ImageCropper::transform(const cv::Mat& image)
{
	const int x = center_.get_x() - size_ / 2;
	const int y = center_.get_y() - size_ / 2;
	const cv::Rect roi_rect(x,y,size_,size_);
	return image(roi_rect);
}

void ImageCropper::set_params(int size, Point center)
{
	size_ = size;
	center_ = center;
}

void ImageCropper::set_size(int size)
{
	size_ = size;
}

void ImageCropper::set_new_center(Point new_center)
{
	center_ = new_center;
}
