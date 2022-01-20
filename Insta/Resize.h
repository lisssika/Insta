#pragma once
#include <opencv2/opencv.hpp>

template <typename ... Arguments>
class Resize
{
public:
	virtual cv::Mat zoom_in(const cv::Mat& image, Arguments ... scale) = 0;
	virtual cv::Mat zoom_out(const cv::Mat& image, Arguments ... scale) = 0;
	virtual cv::Mat zoom(const cv::Mat& image, Arguments ... scale) = 0;
	virtual ~Resize() = default;
};

class ProportionalResize final : public Resize<double>
{
public:
	cv::Mat zoom_in(const cv::Mat& image, double xy_scale) override;
	cv::Mat zoom_out(const cv::Mat& image, double xy_scale) override;
	cv::Mat zoom(const cv::Mat& image, double xy_scale) override;
};

