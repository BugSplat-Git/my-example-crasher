#include "Editor.h"

Editor::Editor(Thingy *thingy) {
	this->thingy = thingy;
}

void Editor::Edit() {
	thingy->Edit();
}

void Editor::Save() {
	thingy->Save(L"/does/not/exist");
}