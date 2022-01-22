#pragma once
#include <opencv2/imgcodecs.hpp>
#include <memory>
class InstagramEditor
{
public:
	InstagramEditor(const std::unique_ptr<cv::Mat>& image );
private:
	cv::Mat image_;

};

