#include "Resize.h"

#include "DoubleIsEqual.h"

cv::Mat SeparateScale::operator()(const cv::Mat& image, double x_scale, double y_scale)
{
	return scale(image, x_scale, y_scale);
}

cv::Mat SeparateScale::scale(const cv::Mat& image, const double x_scale, const double y_scale)
{
	int new_cols = static_cast<int>(image.cols * x_scale);
	int new_rows = static_cast<int>(image.rows * y_scale);
	if (new_cols!= 0 && new_rows!= 0)
	{
		cv::Mat scaled_image;
		cv::resize(image, scaled_image, { new_cols, new_rows }, 0, cv::INTER_LINEAR);
		return scaled_image;
	}
	return image;
}

cv::Mat ProportionalScale::operator()(const cv::Mat& image, double xy_scale)
{
	return scale(image, xy_scale, xy_scale);
}
