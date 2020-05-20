#pragma once
#include "Thingy.h"

class Gizmo : public Thingy
{
public: 
	Gizmo(void);
	void Edit(void) override;
	void Save(LPCWSTR filePath) override;
};

