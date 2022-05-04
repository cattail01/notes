#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
int WINAPI /*CALLBACK*/ WinMain	// WINAPI CALLBACK	¶¼ÊÇ _stdcall	(# define * _stdcall)
	(HINSTANCE hInstance,
	HINSTANCE hPrevIstance,
	PSTR szCmdLine,
	int iCmdShow)
{
	MessageBox(NULL, L"hello api", L"hello demo", MB_OK);
}
