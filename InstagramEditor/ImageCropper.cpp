#include "ImageCropper.h"
#include "Point.h"
#include <opencv2/core/mat.hpp>

namespace
{
	bool is_point_in_image(const cv::Mat& image, const Point& point)
	{
		const bool point_x_ok = point.get_x() >= 0 && point.get_x() < image.cols;
		const bool point_y_ok = point.get_y() >= 0 && point.get_y() < image.rows;
		return point_x_ok && point_y_ok;
	}

	cv::Mat crop(const cv::Mat& original_image, int new_width, int new_heigth, const Point& left_up_point)
	{
		const Point right_bottom_point = left_up_point + Point{ new_width, new_heigth };
		const bool area_in_image = is_point_in_image(original_image, left_up_point)
													&& is_point_in_image(original_image, right_bottom_point);
		if (!area_in_image)
		{
			throw std::runtime_error("cropped area is over the image");
		}

		const cv::Rect roi_rect(left_up_point.get_x(), left_up_point.get_y(), new_width, new_heigth);
		return original_image(roi_rect);
	}
}

cv::Mat SqrImageCropper::transform()
{
	return crop(original_image_, size_, size_, left_up_point_);
}

void SqrImageCropper::set_parameters(int size, const Point& left_up_point, const cv::Mat& image)
{
	size_ = size;
	left_up_point_ = left_up_point;
	image.copyTo(original_image_);
}
