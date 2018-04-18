#include"SV.h"

wchar_t* Readfile(wchar_t* filepath) {
	wchar_t *str = (wchar_t*)malloc(sizeof(wchar_t));

	FILE *f = _wfopen(filepath, L"r,ccs=UTF-16LE");

	wchar_t c = fgetwc(f);
	int n = 1;
	while (c != 'EOF') {
		str = (wchar_t*)realloc(str, (n + 1) * sizeof(wchar_t));
		str[n - 1] = c;
		c = fgetwc(f);
		n++;
	}
	str[n] = L'\0';

	fclose(f);
	return str;
}

bool Check(bool flag, wchar_t p, wchar_t delim) {
	if (flag == true)
		return false;
	return p == L',';
}

// Viết lại hàm theo mẫu wcstok để ko cắt token tại dấu , giữa 2 dấu "
wchar_t* Token(wchar_t *in, wchar_t delim, wchar_t excpt) {
	static wchar_t* itr = NULL;
	if (in == NULL) {
		if (itr == NULL)
			return NULL;
		else
			in = itr;
	}

	wchar_t* p2 = in;
	bool flag = false;
	while (!Check(flag, *p2, L'\"')) {
		if (*p2 == NULL) {
			itr = NULL;
			return in;
		}
		if (*p2 == excpt) {
			flag = !flag;
			*p2 = ' ';
		}
		p2++;
	}
	*p2 = '\0';
	itr = p2+1;
	return in;
}

void FileToSV(SV& sv, wchar_t* filepath) {
	wchar_t* str = Readfile(filepath);

	wchar_t* p = Token(str, L',', L'\"');
	sv.InsName(p);
	p = Token(NULL, L',', L'\"');
	sv.InsMSSV(p);
	p = Token(NULL, L',', L'\"');
	sv.InsFac(p);
	p = Token(NULL, L',', L'\"');
	sv.InsYear(p);
	p = Token(NULL, L',', L'\"');
	sv.InsMail(p);
	p = Token(NULL, L',', L'\"');
	sv.InsDob(p);
	p = Token(NULL, L',', L'\"');
	sv.InsDes(p);

	p = Token(NULL, L',', L'\"');
	while (p) {
		sv.InsHobby(p);
		p = Token(NULL, L',', L'\"');
	}
}