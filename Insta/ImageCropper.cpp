#include "ImageCropper.h"
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

namespace
{
	bool check_coord(int coord, int half_size, int length)
	{
		const bool one_side_ok = coord + half_size <= length;
		const bool another_side_ok = coord >= half_size;
		return one_side_ok && another_side_ok;
	}
}

ImageCropper::ImageCropper(int size, const Point& center):size_(size), center_(center){}

cv::Mat ImageCropper::transform(const cv::Mat& image)
{
	const int center_x = center_.get_x();
	const int center_y = center_.get_y();
	const int half_size = size_/2;
	const bool center_x_ok = check_coord(center_x, half_size, image.cols);
	const bool center_y_ok = check_coord(center_y, half_size, image.rows);
	if (!center_x_ok || !center_y_ok)
	{
		throw std::runtime_error("cropped area is over the image");
	}
	const int x = center_x - half_size;
	const int y = center_y - half_size;
	const cv::Rect roi_rect(static_cast<int> (x), static_cast<int>(y), static_cast<int>(size_), static_cast<int>(size_));
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
