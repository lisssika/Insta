#include "EditorCommand.h"

EditorCommand::EditorCommand(const std::shared_ptr<cv::Mat>& image)
															:image_(image) {}