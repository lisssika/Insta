#include "ImageResize.h"
#include <opencv2/opencv.hpp>
ImageResize::ImageResize(const std::shared_ptr<cv::Mat>& image, int scale):EditorCommand(image), percent_scale_(scale)
{
}

void ImageResize::redo()
{
	*image_ = scale_method_.zoom(*image_, percent_scale_/ 100.);
}

void ImageResize::undo()
{
	*image_ = scale_method_.zoom(*image_, 100. / static_cast<double>(percent_scale_)); // но ведь так потеряется качество
}