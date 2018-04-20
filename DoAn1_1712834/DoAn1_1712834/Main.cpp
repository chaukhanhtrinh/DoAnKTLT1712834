#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include <fcntl.h> 
#include <io.h>
#include"SV.h"
#include"HTML.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	CSDL dsvs;
	FileToSV(dsvs, L"dl1.csv");

	InDL(dsvs);
	
	FreeCSDL(dsvs);
	
	/*
	wchar_t scr[] = L"123 Test 123 Test 213";
	wchar_t f[] = L"Test";
	wchar_t rw[] = L"Replaced";

	wchar_t *wcs = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(scr) + 1));
	for (int i = 0; i < 9; i++) {
		memcpy(wcs, scr, sizeof(wchar_t)*(wcslen(scr) + 1));
		wprintf(L"Before: %ls\n", wcs);
		FindNReplace(wcs, f, rw);
		wprintf(L"After: %ls\n", wcs);
	}*/
	_getche();
	return 0;
}