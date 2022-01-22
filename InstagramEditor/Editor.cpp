#include "Editor.h"

void Editor::execute(const std::unique_ptr<EditorCommand>& cmd)
{
	cmd->redo();
}
