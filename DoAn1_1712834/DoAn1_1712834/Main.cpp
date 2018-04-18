#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include <fcntl.h> 
#include <io.h>
#include"SV.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	SV sv;
	FileToSV(sv, L"Tri.csv");

	In(sv);

	FreeSV(sv);

	_getche();
	return 0;
}