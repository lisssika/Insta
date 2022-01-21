#include "ResizeCmd.h"
#include <opencv2/opencv.hpp>
ResizeCmd::ResizeCmd(const std::shared_ptr<cv::Mat>& image, int scale):EditorCommand(image), percent_scale_(scale)
{
}

void ResizeCmd::redo()
{
	*image_ = scale_method_.zoom(*image_, percent_scale_/ 100.);
}