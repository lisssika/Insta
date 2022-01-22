#include "EditorCommand.h"
#include <opencv2/core/mat.hpp>

EditorCommand::EditorCommand(const std::shared_ptr<cv::Mat>& image)
															:image_(image) {}