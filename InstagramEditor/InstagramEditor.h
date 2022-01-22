#pragma once
#include <memory>
#include <opencv2/core/mat.hpp>
class InstagramEditor
{
public:
	InstagramEditor(const std::unique_ptr<cv::Mat>& image );
private:
	cv::Mat image_;

};

