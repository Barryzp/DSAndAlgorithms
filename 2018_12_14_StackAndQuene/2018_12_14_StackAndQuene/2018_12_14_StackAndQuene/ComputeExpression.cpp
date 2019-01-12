#include "Tools.h"
ComputeExpression::ComputeExpression()
{
	this->operationStack = LinkedStack();
	this->operatorStack = LinkedStack();
	this->expressionLength = 0;
	this->suffixExpression = NULL;
}

ComputeExpression::~ComputeExpression()
{

}

void ComputeExpression::InitialSuffixExpression()
{
	char *str = new char[EXPRESSIONLENGTH];
	cout << "请输入表达式：" << endl;
	cin >> str;

	this->expressionLength = strlen(str);
	for (int index = 0; index < this->expressionLength; index++)
	{
		printf("%d",(int)str[index]);
	}
}

int ComputeExpression::StrToInt(string str)
{
	stringstream ss;
	int returnedVal = 0;

	ss << str;
	ss >> returnedVal;
	ss.clear();

	return returnedVal;
}

void ComputeExpression::PrintExpression()
{

}
