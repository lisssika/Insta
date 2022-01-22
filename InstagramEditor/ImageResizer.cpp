#include "ImageResizer.h"

#include <stdexcept>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>

#include "DoubleСomparison.h"

namespace 
{
	void validation_size(int pixel_count)
	{
		if (pixel_count <= 0)
		{
			throw std::runtime_error("pixel_count is invalid");
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
		cv::resize(image, scaled_image, { new_cols, new_rows }, 0, 0, interpolation);
		return scaled_image;
	}

	cv::Mat zoom_in(const cv::Mat& image, double x_scale, double y_scale)
	{
		return resize(image, x_scale, y_scale, cv::INTER_CUBIC);
	}

	cv::Mat zoom_out(const cv::Mat& image, double x_scale, double y_scale)
	{
		return resize(image, x_scale, y_scale, cv::INTER_CUBIC);
	}



}

void ImageProportionalResizer::set_parameters(double scale)
{
	if (double_is_lower(scale, 0.)||double_is_equal(scale, 0.))
	{
		throw std::runtime_error("scale is not positive!");
	}
	scale_ = scale;
}

cv::Mat ImageProportionalResizer::transform(const cv::Mat& original_image)
{
	if (scale_ > 1.)
	{
		return zoom_in(original_image, scale_, scale_);
	}
	else
	{
		return zoom_out(original_image, scale_, scale_);
	}
}


