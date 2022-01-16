#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <memory>
class EditorCommand
{
public:
	EditorCommand(const std::shared_ptr<cv::Mat>& image);
	virtual void redo() = 0;
	virtual void undo() = 0;
	virtual ~EditorCommand() = default;
protected:
	std::shared_ptr<cv::Mat> image_;
};

