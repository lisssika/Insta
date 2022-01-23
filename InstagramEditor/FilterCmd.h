#pragma once
#include "ImageFilter.h"
#include "EditorCommand.h"
class FilterCmd final : public EditorCommand 
{
public:
	//FilterCmd();
	//virtual void redo() override;
private:
	ImageFilter filter_;
};

