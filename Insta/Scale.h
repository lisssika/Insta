#pragma once
#include <opencv2/opencv.hpp>

template <typename ... Arguments>
class Scale
{
public:
	virtual cv::Mat operator()(const cv::Mat& image, Arguments ... scale) = 0;
	virtual ~Scale() = default;
};

class SeparateScale : public Scale<double, double> // можно ещё сделать раздеение алгоритмов на увеличивающие и сжимающие
{
public:
	cv::Mat operator()(const cv::Mat& image, double x_scale, double y_scale) override;
protected:
	static cv::Mat scale(const cv::Mat& image, double x_scale, double y_scale);
};

class ProportionalScale final : public Scale<double>, private SeparateScale
{
public:
	cv::Mat operator()(const cv::Mat& image, double scale) override;
};

