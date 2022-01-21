#include "SqrCroppCmd.h"

SqrCroppCmd::SqrCroppCmd(const std::shared_ptr<cv::Mat>& image, const Point& center, int size):
												EditorCommand(image), center_(center), size_(size)
{
	cropper_ = std::make_unique<ImageCropper>(size, center);
}

void SqrCroppCmd::redo()
{
	*image_ = cropper_->transform(*image_);
}
