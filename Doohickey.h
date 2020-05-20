#pragma once
#include "Thingy.h"
#include <string>

class Doohickey : public Thingy {
public:
	Doohickey(void);
	void Edit(void) override;
	void Save(LPCWSTR filePath) override;
};