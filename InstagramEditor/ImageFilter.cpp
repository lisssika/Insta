#include "ImageFilter.h"

void ImageFilter::set_parameters( int intensity, int type)
{
	current_ = type;
	intensity_ = intensity;
	switch (type)
	{

	case FilterType::mercury:
		filter_strategy_ = std::make_unique<Mercury>();
		break;
	case FilterType::venus:
		filter_strategy_ = std::make_unique<Venus>();
		break;
	case FilterType::mars:
		filter_strategy_ = std::make_unique<Mars>();
		break;
	default:
		filter_strategy_ = std::make_unique<Earth>();
		current_ = 0; // problems?
		break;
	}
}

void ImageFilter::set_next( int intensity)
{
	current_++;// problems?
	set_parameters( intensity, current_);
}

void ImageFilter::set_previous( int intensity)
{
	current_--; // problems?
	set_parameters( intensity, current_);
}

void ImageFilter::set_image(const cv::Mat& image)
{
	image.copyTo(original_image_);
}



cv::Mat ImageFilter::transform()
{
	return filter_strategy_->apply(original_image_, intensity_);
}
