#pragma once
#include "EditorCommand.h"
#include "Resize.h"
#include <opencv2/opencv.hpp>
#include <memory>
class ImageResize final : public EditorCommand
{
public:
	ImageResize(const std::shared_ptr<cv::Mat>& image, int scale);
	virtual void redo() override;
	virtual void undo() override;
private:
	int percent_scale_;
	ProportionalResize scale_method_;
};
