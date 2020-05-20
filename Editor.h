#pragma once
#include "Thingy.h"

class Editor {
public: 
	Editor(Thingy *thingy);
	void Edit(void);
	void Save(void);

private:
	Thingy *thingy;
};