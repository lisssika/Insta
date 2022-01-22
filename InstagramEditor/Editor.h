#pragma once
#include "EditorCommand.h"
#include <memory>
#include <vector>

class Editor
{
public:
	void execute(const std::unique_ptr<EditorCommand>& cmd);
	//void add_and_execute(const std::unique_ptr<EditorCommand>& cmd);
	//void undo();
	//void redo();
	//void ctr_z_click();
private:
	std::vector<std::unique_ptr<EditorCommand>>	history_;
};
