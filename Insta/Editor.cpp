#include "Editor.h"

void Editor::addAndExecuteCommand(std::unique_ptr<EditorCommand> cmd)
{
	cmd->redo();
	commands_.push_back(std::move(cmd));
}

void Editor::undo()
{
	if (commands_.empty()) return;
	commands_.at(commands_.size() - 1)->undo();
	commands_.pop_back();
}
