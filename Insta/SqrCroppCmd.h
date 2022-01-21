#pragma once
#include "EditorCommand.h"
#include "Point.h"
#include "ImageCropper.h"
#include <memory>

class SqrCroppCmd final : public EditorCommand
{
public:
	SqrCroppCmd(const std::shared_ptr<cv::Mat>& image, const Point& center, int size);
	virtual void redo() override;
private:
	Point center_;
	int size_;
	std::unique_ptr<ImageCropper> cropper_;
};