#include "CropCmd.h"

CropCmd::CropCmd(const std::shared_ptr<cv::Mat>& image, const Point& center, int size):
			EditorCommand(image), center_(center), size_(size)
{
}

void CropCmd::redo()
{
}
