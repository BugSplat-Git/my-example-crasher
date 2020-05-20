#pragma once
#include <Windows.h>

class FileSystemUtils {
public:
	static void Save(LPCWSTR filePath, char buffer[]);
};