#pragma once
#include "EditorCommand.h"
#include "Scale.h"
#include <opencv2/opencv.hpp>
#include <memory>
class ImageScale final : public EditorCommand
{
public:
	ImageScale(const std::shared_ptr<cv::Mat>& image, int scale);
	virtual void redo() override;
	virtual void undo() override;
private:
	int percent_scale_;
	ProportionalScale scale_method_;
};

