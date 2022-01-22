#pragma once
#include <memory>
#include <opencv2/imgcodecs.hpp>
class EditorCommand
{
public:
	EditorCommand(const std::shared_ptr<cv::Mat>& image); // unique???
	virtual void redo() = 0;
	virtual ~EditorCommand() = default;
private:
	std::shared_ptr<cv::Mat> image_;
};
