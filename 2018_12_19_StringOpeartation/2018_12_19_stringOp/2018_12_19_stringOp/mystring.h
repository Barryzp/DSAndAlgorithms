#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class StringOpearation
{
public:
	void StrCopy(char *t,char *s);
	void ClearStr(char *s);
	bool IsStrEmpty(char *s);
	int StrLength(char *s);
	int StrCompare(char *s,char *t);
	char * Concat(char *s1,char *s2);
	char * SubString(char *s,int pos,int length);
	int Index(char *s,char *t,int pos);
	void Replace(char *s,char *s1,char *s2);
};
