#include <windows.h>
#include <iostream>
#include <cstring>

using std::string;

void CopyTextToClipboard(const string& text)
{
	if (!OpenClipboard(nullptr))
		return;

	EmptyClipboard();

	HGLOBAL hClipboardData = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
	if (hClipboardData == nullptr)
	{
		CloseClipboard();
		return;
	}

	char* pClipboardData = static_cast<char*>(GlobalLock(hClipboardData));
	if (pClipboardData != nullptr)
	{
		strcpy_s(pClipboardData, text.size() + 1, text.c_str());
		GlobalUnlock(hClipboardData);
	}

	SetClipboardData(CF_TEXT, hClipboardData);

	CloseClipboard();
}