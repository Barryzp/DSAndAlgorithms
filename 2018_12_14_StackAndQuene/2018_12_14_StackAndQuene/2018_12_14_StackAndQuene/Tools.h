#pragma once
#include "restrainedList.h"
#include <sstream>

class ComputeExpression
{
public:
	ComputeExpression();
	~ComputeExpression();

	void InitialSuffixExpression();
	void PrintExpression();
	int StrToInt(string str);
private:
	LinkedStack operatorStack;
	LinkedStack operationStack;
	char *suffixExpression;
	int expressionLength;
};
