#include "CropCmd.h"

CropCmd::CropCmd(const std::shared_ptr<cv::Mat>& image, const Point& center, int size):
			EditorCommand(image), image_(image), center_(center), size_(size)
{
	const Point left_up_point = center - Point{ size_ / 2, size_ / 2 };
	cropper_.set_parameters(size_, left_up_point, *image_); // кидает исключения, если так обрезать невозможно
}

void CropCmd::redo()
{
	*image_ = cropper_.transform();
}
