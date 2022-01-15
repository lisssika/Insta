#pragma once
#include "EditorCommand.h"
#include "Point.h"
#include <opencv2/opencv.hpp>
#include <memory>

class ImageCropp :public EditorCommand
{
	ImageCropp(std::shared_ptr<cv::Mat>, const Point& center); // ��� � ������ variadic template � ������ ���������
	virtual void redo() override;
	virtual void undo() override;
};

