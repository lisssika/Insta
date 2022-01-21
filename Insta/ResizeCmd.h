#pragma once
#include "EditorCommand.h"
#include "Resize.h"
#include <opencv2/opencv.hpp>
#include <memory>
class ResizeCmd final : public EditorCommand
{
public:
	ResizeCmd(const std::shared_ptr<cv::Mat>& image, int scale);
	virtual void redo() override;
private:
	int percent_scale_;
	ProportionalResize scale_method_;
};

