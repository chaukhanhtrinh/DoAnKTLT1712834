#include"HTML.h"
#include"SV.h"

void FindNReplace(wchar_t *&wcs, wchar_t *f, wchar_t *rw) {
	wchar_t *p = wcsstr(wcs, f);

	while (p) {
 		wchar_t *temp = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(wcs) + wcslen(rw) - wcslen(f) + 1));
		wcsncpy(temp, wcs, (p - wcs));
		wcsncpy(temp + (p - wcs), rw, wcslen(rw));
		wcscpy(temp + (p - wcs) + wcslen(rw), wcs + (p - wcs + wcslen(f)));
		
		free(wcs);
		wcs = temp;
		p = wcsstr(wcs, f);
	}
}

void CreateAPage(wchar_t *t_html, SV t_sv, SV sv) {
	FILE *f = _wfopen(t_html, L"r,ccs=UTF-16LE");


}