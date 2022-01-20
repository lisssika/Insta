#include "Resize.h"
#include "DoubleIsEqual.h"
#include "exception"
namespace 
{
	void validation_size(int& pizel_count)
	{
		if (pizel_count<0)
		{
			throw std::runtime_error("pizel_count is invalid");
		}
		if (pizel_count == 0)
		{
			pizel_count = 1;
		}
	}

	cv::Mat resize(const cv::Mat& image, const double x_scale, const double y_scale,
	               int interpolation = cv::INTER_LINEAR)
	{
		if (double_is_lower(x_scale, 0.) || double_is_lower(y_scale, 0.))
		{
			throw std::runtime_error("scale is not positive!");
		}
		int new_cols = static_cast<int>(image.cols * x_scale);
		int new_rows = static_cast<int>(image.rows * y_scale);
		validation_size(new_cols); // переменное число параметров хорошо бы
		validation_size(new_rows);
		assert(new_cols != 0 && new_rows != 0);
		cv::Mat scaled_image;
		cv::resize(image, scaled_image, {new_cols, new_rows}, 0, 0, interpolation);
		return scaled_image;
	}
}

cv::Mat ProportionalResize::zoom_in(const cv::Mat& image, double xy_scale)
{
	if (xy_scale > 1)
	{
		return resize(image, xy_scale, xy_scale, cv::INTER_CUBIC);
	}
	return  image;
}

cv::Mat ProportionalResize::zoom_out(const cv::Mat& image, double xy_scale)
{
	if (xy_scale < 1)
	{
		return resize(image, xy_scale, xy_scale, cv::INTER_CUBIC);
	}
	return image;
}

cv::Mat ProportionalResize::zoom(const cv::Mat& image, double xy_scale)
{
	if (double_is_lower(xy_scale, 1.))
	{
		return zoom_out(image, xy_scale);
	}
	else
	{
		return zoom_in(image, xy_scale);
	}
}

