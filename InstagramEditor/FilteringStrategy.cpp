#include "FilteringStrategy.h"

#include <opencv2/imgproc.hpp>


cv::Mat Mercury::apply(const cv::Mat& image, int intensity)
{
	cv::Mat filtered_image;
	cv::cvtColor(image, filtered_image, cv::COLOR_BGR2GRAY, intensity*255/100);
	return  filtered_image;
}

cv::Mat Venus::apply(const cv::Mat& image, int intensity)
{
	cv::Mat filtered_image;
	cv::cvtColor(image, filtered_image, cv::COLOR_BGR2GRAY, intensity * 255 / 100);
	return  filtered_image;
}

cv::Mat Earth::apply(const cv::Mat& image, int intensity)
{
	cv::Mat filtered_image;
	image.copyTo(filtered_image);
	//cv::cvtColor(image, filtered_image, cv::COLOR_BGR2GRAY, intensity * 255 / 100);
	return  filtered_image;
}

cv::Mat Mars::apply(const cv::Mat& image, int intensity)
{
	cv::Mat filtered_image;
	cv::cvtColor(image, filtered_image, cv::COLOR_BGR2GRAY, intensity * 255 / 100);
	return  filtered_image;
}
