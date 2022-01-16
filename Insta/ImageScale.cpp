#include "ImageScale.h"
#include <opencv2/opencv.hpp>
ImageScale::ImageScale(const std::shared_ptr<cv::Mat>& image, int scale):EditorCommand(image), percent_scale_(scale)
{
}

void ImageScale::redo()
{
	*image_ = scale_method_(*image_, static_cast<double>(percent_scale_) / 100.);
} // почему-то удаляется image

void ImageScale::undo()
{
	scale_method_(*image_, 100. / static_cast<double>(percent_scale_)).copyTo(*image_); // но ведь так потеряется качество
}

