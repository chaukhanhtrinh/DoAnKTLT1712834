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
	wchar_t *mssv;
	wchar_t *fac;
	int year;
	wchar_t *mail;
	wchar_t *dob;
	wchar_t *image;
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

	void InsName(wchar_t* _name) {
		name = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_name) + 1));
		memcpy(name, _name, sizeof(wchar_t)*(wcslen(_name)+1));
	}
	void InsMSSV(wchar_t* _mssv) {
		mssv = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_mssv) + 1));
		memcpy(mssv, _mssv, sizeof(wchar_t)*(wcslen(_mssv) + 1));
	}
	void InsFac(wchar_t* _fac) {
		fac = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_fac) + 1));
		memcpy(fac, _fac, sizeof(wchar_t)*(wcslen(_fac)+1));
	}
	void InsYear(wchar_t* _year) {
		wchar_t *p = _year;
		while (*p) {
			year *= 10;
			year += *p - L'0';
			p++;
		}
	}
	void InsMail(wchar_t* _mail) {
		mail = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_mail) + 1));
		memcpy(mail, _mail, sizeof(wchar_t)*(wcslen(_mail) + 1));
	}
	void InsDob(wchar_t* _dob) {
		dob = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_dob) + 1));
		memcpy(dob, _dob, sizeof(wchar_t)*(wcslen(_dob) + 1));
	}
	void InsImg(wchar_t* _Img) {
		image = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_Img) + 1));
		memcpy(image, _Img, sizeof(wchar_t)*(wcslen(_Img) + 1));
	}
	void InsDes(wchar_t* _des) {
		des = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_des) + 1));
		memcpy(des, _des, sizeof(wchar_t)*(wcslen(_des)+1));
	}
	void InsHobby(wchar_t* _hobby) {
		hobby = (wchar_t**)realloc(hobby, sizeof(wchar_t*)*(hobby_count + 1));
		hobby[hobby_count] = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_hobby) + 1));
		memcpy(hobby[hobby_count], _hobby, sizeof(wchar_t)*(wcslen(_hobby) + 1));
		hobby_count++;
	}
};

wchar_t* Readfile(wchar_t* filepath);
bool Check(bool flag, wchar_t p, wchar_t delim);
wchar_t* Token(wchar_t *in, wchar_t delim, wchar_t excpt);
void FileToSV(SV& sv, wchar_t* filepath);
void In(SV sv);
void FreeSV(SV &sv);


#endif