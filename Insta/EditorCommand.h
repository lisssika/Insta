#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <memory>
class EditorCommand
{
public:
	EditorCommand(std::shared_ptr<cv::Mat>);
	virtual void redo() = 0;
	virtual void undo() = 0;
private:
	std::shared_ptr<cv::Mat> image_;
};

