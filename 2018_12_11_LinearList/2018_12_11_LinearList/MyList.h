#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MAXSIZE 10
#define ERROR_INDEX_OVER 0
#define SUCCESS 1

typedef int status;
typedef struct BasicNode
{
	string content;
	int index;
}Node;

class RankedStrorageList
{
public:
	RankedStrorageList();
	~RankedStrorageList();
	void ShowWindow();
	Node GetItemByIndex(int index);
	Node DeleteItemByIndex(int index);
	status AddItemByIndex(int index,Node item);
	int GetLength();
	void IncreaseSpace();
	void ReverseArray();
private:
	Node* RSList;
	int length;
	int space;
};

