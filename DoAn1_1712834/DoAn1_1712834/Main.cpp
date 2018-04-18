#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include <fcntl.h> 
#include <io.h>
#include"SV.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t test[] = L"Trường 1,Trường 2,\"Trường, 3\",\"Trường, 4\"";
	wchar_t *p = Token(test, L',', L'\"');
	int n = 1;
	while (p) {
		wprintf(L"%d: %ls\n",n++, p);
		p = Token(NULL, L',', L'\"');
	}

	_getche();
	return 0;
}