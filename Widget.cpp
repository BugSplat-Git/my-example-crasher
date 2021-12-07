#include "Gadget.h"
#include "Widget.h"
#include "FileSystemUtils.h"
#include <iostream>

Widget::Widget() { };

void Widget::Edit(void) {
	std::cout << "Editting the Widget...\n";
}

void Widget::Save(LPCWSTR filePath) {
	std::cout << "Saving the Widget...\n";
	Gadget::Write(filePath, "Widget!");
}
