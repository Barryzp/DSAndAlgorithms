#include "mystring.h"
bool StringOpearation::IsStrEmpty(char *s)
{
	if (this->StrLength(s)==0)
	{
		return true;
	}
	return false;
}


void StringOpearation::StrCopy(char *t, char *s)
{
	int length = this->StrLength(s);

	for (int index=0;index<length;index++)
	{
		t[index] = s[index];
	}
}
void StringOpearation::ClearStr(char *s)
{
	int length = this->StrLength(s);
	for (int i = 0; i < length; i++)
	{
		s[i] = '\0';
	}
}
int StringOpearation::StrLength(char *s)
{
	char nullChar = '\0';
	int length = 0;
	while (s[length]!=nullChar)
	{
		length++;
	}

	return length;
}
int StringOpearation::StrCompare(char *s, char *t)
{
	int sLength = this->StrLength(s);
	int tLength = this->StrLength(t);
	int minLength = -1;
	if (sLength>tLength)
	{
		minLength = tLength;
	}
	else
	{
		minLength = sLength;
	}

	for (int i = 0; i < minLength; i++)
	{
		if (s[i]<t[i])
		{
			return 1;
		}
		else if (s[i]==t[i])
		{

		}else
		{
			return -1;
		}
	}

	if (sLength>tLength)
	{
		return -1;
	}
	else if (sLength==tLength)
	{
		return 0;
	}
	return 1;
}
char * StringOpearation::Concat(char *s1, char *s2)
{
	int s1L = this->StrLength(s1);
	int s2L = this->StrLength(s2);
	char* t = new char[s1L + s2L];

	for (int i = 0; i < s1L; i++)
	{
		t[i] = s1[i];
	}

	for (int i = 0; i < s2L; i++)
	{
		t[i + s1L] = s2[i];
	}
	return t;
}
char* StringOpearation::SubString(char *s, int pos, int length)
{
	char *sub = new char[length];
	int sL = this->StrLength(s);
	for (int i = 0; i < length; i++)
	{
		sub[i] = s[pos + i-1];
	}
	return sub;
}
int StringOpearation::Index(char *s, char *t, int pos)
{
	return 0;
}
void StringOpearation::Replace(char *s, char *s1, char *s2)
{

}