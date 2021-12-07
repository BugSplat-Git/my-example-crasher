#include "Gadget.h"
#include "FileSystemUtils.h"

void Gadget::Write(LPCWSTR filePath, char buffer[]) {
	FileSystemUtils::Save(filePath, buffer);
}
