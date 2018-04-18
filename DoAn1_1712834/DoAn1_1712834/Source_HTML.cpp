#define _CRT_SECURE_NO_WARNINGS
#include"CreateHTML.h"

void Title(wchar_t str[], wchar_t name[]) {
	int i = 0;
	while (str[i] != '<')
		i++;
	int y = i + 1;
	while (str[y] != '<')
		y++;

	wchar_t t[] = L"<title>HCMUS - ";
	wchar_t n[] = L"</title>\n";
	wchar_t temp[100];
	wcscpy(temp, str + y);
	wcsncpy(str + i + wcslen(t), name, wcslen(name));
	wcscpy(str + i + wcslen(t)+ wcslen(name), temp);
}

void NameAndMS(wchar_t str[], wchar_t name[], wchar_t MS[]) {
	int i = 0;
	while (str[i] != '<')
		i++;

	int y = i + 1;
	while (str[y] != '<')
		y++;

	wchar_t t[] = L"<span class=\"Personal_FullName\">";
	wchar_t n[] = L"</span>\n";
	
	wchar_t content[100];
	wcscpy(content, name);
	wcscpy(content + wcslen(content), L" - ");
	wcscpy(content + wcslen(content), MS);

	wchar_t temp[100];
	wcscpy(temp, str + y);
	wcsncpy(str + i + wcslen(t), content, wcslen(content));
	wcscpy(str + i + wcslen(t) + wcslen(content), temp);
}

void Phone(wchar_t str[], wchar_t name[]) {
	int i = 0;
	while (str[i] == ' ')
		i++;
	wcscpy(str + i, name);
}

void Picture(wchar_t str[], wchar_t pic[]) {
	int i = 0;
	while (str[i] != '<')
		i++;
	int y = i + 1;
	while (str[y] != '"')
		y++;

	wchar_t t[] = L"<img src=\"";
	wchar_t n[] = L"\" class = \"Personal_Hinhcanhan\" / >\n";
	wchar_t temp[100];
	wcscpy(temp, str + y);
	wcsncpy(str + i + wcslen(t), pic, wcslen(pic));
	wcscpy(str + i + wcslen(t) + wcslen(pic), temp);
}

void Info(wchar_t str[], wchar_t info[], wchar_t _info[]) {
	int i = 0;
	while (str[i] != '<')
		i++;

	int y = i + 1;
	while (str[y] != '<')
		y++;

	wchar_t t[] = L"<li>";
	wchar_t n[] = L"</li>\n";

	wchar_t content[100];
	wcscpy(content, info);
	wcscpy(content + wcslen(content), L" ");
	wcscpy(content + wcslen(content), _info);

	wchar_t temp[100];
	wcscpy(temp, str + y);
	wcsncpy(str + i + wcslen(t), content, wcslen(content));
	wcscpy(str + i + wcslen(t) + wcslen(content), temp);
}

void Run() {
	FILE *f = _wfopen(L"1212123.htm", L"r,ccs=UTF-16LE");
	FILE *out = _wfopen(L"test.htm", L"w,ccs=UTF-16LE");
	int i = 1;

	wchar_t name[] = L"Trần Minh Trí";
	wchar_t mssv[] = L"1712834";
	wchar_t mail[] = L"Mail: 1712834@student.hcmus.edu.vn\n";
	wchar_t picfile[] = L"Images/tri.png";
	wchar_t dob[] = L"11/06/1999";

	while (!feof(f)) {
		wchar_t temp[1000];
		fgetws(temp, 1000, f);
		if (i == 6)					// Tên tiêu đề web
			Title(temp,name);
		if (i == 23)				// Tên tiêu đề 
			NameAndMS(temp, name, mssv);
		if (i == 27)				// Số đt
			Phone(temp, mail);
		if (i == 34)				// Hình đại diện
			Picture(temp, picfile);
		if (i == 47)
			Info(temp, L"Họ và tên:", name);
		if (i == 48)
			Info(temp, L"MSSV:", mssv);
		
		if (i == 50)
			Info(temp, L"Ngày sinh:", dob);
		if (i == 51)
			Info(temp, L"Email tui nà:", mail+6);

		if (i == 57)
			Info(temp, L"Game:", L"Game gì cũng chơi :v");
		if (i == 58)
			Info(temp, L"Ngủ:", L"T thèm ngủuuuuu");
		if (i == 63)
			Phone(temp, L"T không có mậpppppp! Ú thoy :33\n");

		if (i == 76)
			Phone(temp, L"@2018</br>\n");
		if (i == 79)
			Phone(temp, L"TH2018/03</br>\n");
		if (i == 80)
			Phone(temp, L"MSSV: 1712834 - Sinh viên thực hiện: Trần Minh Trí</br>\n");

		fwprintf(out, L"%ls", temp);
		i++;
	}
	
	fclose(f);
	fclose(out);
}