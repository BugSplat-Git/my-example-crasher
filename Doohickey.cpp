#include "Doohickey.h"
#include "FileSystemUtils.h"
#include <iostream>

Doohickey::Doohickey() { };

void Doohickey::Edit(void) {
	std::cout << "Editting the Doohickey...\n";
}

void Doohickey::Save(LPCWSTR filePath) {
	std::cout << "Saving the Doohickey...\n";
	FileSystemUtils::Save(filePath, "Doohickey!");
}
