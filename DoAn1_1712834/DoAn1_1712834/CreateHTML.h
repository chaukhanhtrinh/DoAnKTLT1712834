#pragma once
#ifndef _CreateHTML_h_
#define _CreateHTML_h_

#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include <fcntl.h> 
#include <io.h>    

void Title(wchar_t str[], wchar_t name[]);
void NameAndMS(wchar_t str[], wchar_t name[], wchar_t MS[]);
void Phone(wchar_t str[], wchar_t name[]);
void Picture(wchar_t str[], wchar_t pic[]);
void Info(wchar_t str[], wchar_t info[], wchar_t _info[]);
void Run();

#endif