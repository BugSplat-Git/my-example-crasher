#pragma once
#include "Thingy.h"
#include "Gadget.h"

class Widget : public Thingy
{
public:
	Widget(void);
	void Edit(void) override;
	void Save(LPCWSTR filePath) override;
private:
	Gadget* gadget;
};

