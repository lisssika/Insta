#pragma once
#include "Window.h"
#include "Editor.h"
#include <memory>
class InstagramEditor
{
public:
	InstagramEditor(const cv::Mat& image);
	void execute();
private:
	Editor editor_;
	cv::Mat original_image_;
	std::shared_ptr<cv::Mat> image_;
};

