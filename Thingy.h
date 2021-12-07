#ifndef THINGY_H
#define THINGY_H

#include "stdafx.h"

class Thingy {
public:
	virtual void Save(LPCWSTR filePath) { }
	virtual void Edit(void) { }
};
#endif