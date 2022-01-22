#pragma once
#include "ImageTransformer.h"
#include <memory>
#include "FilteringStrategy.h"

class ImageFilter :public ImageTransformer
{
public:
	enum FilterType
	{
		earth,
		mercury,
		venus,
		mars
	};
	void set_parameters( int intensity, int type);
	void set_next(int intensity);
	void set_previous(int intensity);
	void set_image(const cv::Mat& image);
	cv::Mat transform() override;
private:
	int intensity_{};
	std::unique_ptr<FilteringStrategy> filter_strategy_;
	int current_{};
};





