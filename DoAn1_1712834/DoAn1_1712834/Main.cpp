#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include <fcntl.h> 
#include <io.h>

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);


	_getche();
	return 0;
}