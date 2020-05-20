#include "Gizmo.h"
#include "FileSystemUtils.h"
#include <iostream>

Gizmo::Gizmo() { };

void Gizmo::Edit(void) {
	std::cout << "Editting the Gizmo...\n";
}

void Gizmo::Save(LPCWSTR filePath) {
	std::cout << "Saving the Gizmo...\n";
	FileSystemUtils::Save(filePath, "Gizmo!");
}
