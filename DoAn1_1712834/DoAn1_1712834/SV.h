#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef _SV_h_
#define _SV_h_

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>

struct SV {
	wchar_t *name;
	char *mssv;
	wchar_t *fac;
	int year;
	char *mail;
	char *dob;
	char *image;
	wchar_t *des;
	unsigned int hobby_count;
	wchar_t **hobby;

	SV() {
		name = NULL;
		mssv = NULL;
		fac = NULL;
		year = 0;
		mail = NULL;
		dob = NULL;
		image = NULL;
		des = NULL;
		hobby_count = 0;
		hobby = NULL;
	}

	void InsName(wchar_t _name[]) {
		name = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_name) + 1));
		memcpy(name, _name, sizeof(wchar_t)*wcslen(_name));
	}
	void InsMSSV(wchar_t _mssv[]) {
		mssv = (char*)malloc(sizeof(char)*(wcslen(_mssv) + 1));
		wcstombs(mssv, _mssv, wcslen(_mssv) + 1);
	}
	void InsFac(wchar_t _fac[]) {
		fac = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_fac) + 1));
		memcpy(name, _fac, sizeof(wchar_t)*wcslen(_fac));
	}
	void InsYear(wchar_t _year[]) {
		wchar_t *p = _year;
		while (*p) {
			year = *p - L'0';
			p++;
		}
	}
	void InsMail(wchar_t _mail[]) {
		mail = (char*)malloc(sizeof(char)*(wcslen(_mail) + 1));
		wcstombs(mail, _mail, wcslen(_mail) + 1);
	}
	void InsDob(wchar_t _dob[]) {
		dob = (char*)malloc(sizeof(char)*(wcslen(_dob) + 1));
		wcstombs(dob, _dob, wcslen(_dob) + 1);
	}
	void InsDes(wchar_t _des[]) {
		des = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_des) + 1));
		memcpy(name, _des, sizeof(wchar_t)*wcslen(_des));
	}
	void InsHobby(wchar_t _hobby[]) {
		hobby = (wchar_t**)realloc(hobby, sizeof(wchar_t*)*(hobby_count + 1));
		hobby[hobby_count] = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_hobby) + 1));
		hobby_count++;
	}
};

wchar_t* Readfile(wchar_t* filepath);
bool Check(bool flag, wchar_t p, wchar_t delim);
wchar_t* Token(wchar_t *in, wchar_t delim, wchar_t excpt);
void FileToSV(SV& sv, wchar_t* filepath);

#endif