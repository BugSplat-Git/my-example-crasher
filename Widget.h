#pragma once
#include "Thingy.h"

class Widget : public Thingy
{
public:
	Widget(void);
	void Edit(void) override;
	void Save(LPCWSTR filePath) override;
};

