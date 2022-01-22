#pragma once
#include <opencv2/opencv.hpp>

#include "Editor.h"
class InstaEditor
{
public:
	InstaEditor(const cv::Mat& image); // потом сделать чтение файлов мб
	void execute();
private:
	Editor editor_;
	std::shared_ptr<cv::Mat> image_;
	cv::Mat original_image_;
};

