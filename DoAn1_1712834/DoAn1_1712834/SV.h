#pragma once
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
	wchar_t *dob;
	wchar_t *mail;
	wchar_t *des;
	unsigned int hobby_count;
	wchar_t **hobby;

	SV() {
		name = NULL;
		mssv = NULL;
		fac = NULL;
		dob = NULL;
		mail = NULL;
		des = NULL;
		hobby_count = 0;
		hobby = NULL;
	}

	void InsName(wchar_t _name[]) {
		name = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_name)+1));
		memcpy(name, _name, sizeof(wchar_t)*wcslen(_name));
	}
	void InsMSSV(wchar_t _mssv[]) {
		mssv = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_mssv)+1));
		memcpy(name, _mssv, sizeof(wchar_t)*wcslen(_mssv));
	}
	void InsFac(wchar_t _fac[]) {
		fac = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_fac)+1));
		memcpy(name, _fac, sizeof(wchar_t)*wcslen(_fac));
	}
	void InsDob(wchar_t _dob[]) {
		dob = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_dob)+1));
		memcpy(name, _dob, sizeof(wchar_t)*wcslen(_dob));
	}
	void InsMail(wchar_t _mail[]) {
		mail = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_mail)+1));
		memcpy(name, _mail, sizeof(wchar_t)*wcslen(_mail));
	}
	void InsDes(wchar_t _des[]) {
		des = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_des)+1));
		memcpy(name, _des, sizeof(wchar_t)*wcslen(_des));
	}
	void InsHobby(wchar_t _hobby[]){
		hobby = (wchar_t**)realloc(hobby, sizeof(wchar_t*)*(hobby_count+1));
		hobby[hobby_count] = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(_hobby)+1));
		hobby_count++;
	}
};

#endif