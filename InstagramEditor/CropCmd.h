#pragma once
#include "ImageCropper.h"
#include "ImageResizer.h"
#include "ImageCropper.h"
#include <memory>
#include "Point.h"
#include "EditorCommand.h"

class CropCmd:public EditorCommand
{
public:
	CropCmd(const std::shared_ptr<cv::Mat>& image, const Point& center, int size);
	virtual void redo() override;
private:
	std::shared_ptr<cv::Mat> image_;
	Point center_;
	int size_;
	SqrImageCropper cropper_;
};
