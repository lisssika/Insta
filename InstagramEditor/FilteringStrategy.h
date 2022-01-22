#pragma once
#include <opencv2/core/mat.hpp>

class FilteringStrategy
{
public:
	virtual cv::Mat apply(const cv::Mat& image, int intensity) = 0;
	virtual  ~FilteringStrategy() = default;
};

class Mercury final:public FilteringStrategy
{
public:
	cv::Mat apply(const cv::Mat& image, int intensity) override;
};

class Venus final :public FilteringStrategy
{
public:
	cv::Mat apply(const cv::Mat& image, int intensity) override;
};

class Earth final :public FilteringStrategy
{
public:
	cv::Mat apply(const cv::Mat& image, int intensity) override;
};

class Mars final :public FilteringStrategy
{
public:
	cv::Mat apply(const cv::Mat& image, int intensity) override;
};
