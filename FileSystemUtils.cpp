#include "FileSystemUtils.h"

void FileSystemUtils::Save(LPCWSTR filePath, char buffer[]) {
	DWORD dwWritten;
	HANDLE hFile;

	hFile = CreateFile(filePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		throw "Could not save file!";
	}

	WriteFile(hFile, buffer, sizeof(buffer), &dwWritten, 0);
	CloseHandle(hFile);
}