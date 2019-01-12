#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MAXSIZE 4
#define MAXSPACE 200
#define ERROR_INDEX_OVER -1
#define INVAILD_INPUT -1
#define NO_MORE_SPACE -1

#define SUCCESS 1

typedef int status;
typedef struct BasicNode
{
	string content;
	int index;
}Node;

/*************************顺序表*****************************/
class RankedStrorageList
{
public:
	RankedStrorageList(Node *ls, int len);
	~RankedStrorageList();
	void ShowWindow();
	Node GetItemByIndex(int index);
	Node DeleteItemByIndex(int index);
	status AddItemByIndex(Node item);
	int GetLength();
	void IncreaseSpace();
	void ReverseArray();
private:
	Node* RSList;
	int length;
	int space;
};

/*************************单链表*****************************/
typedef struct LinkedNode
{
	int data;
	LinkedNode *next;
}LinkedNode;


class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void CreateLS();
	void ShowWindow();
	status AddNode(int index);
	status DeleteNode(int index);
	status FindNodeByIndex(int index);
	void Traverse();

private:
	LinkedNode * head;
	int length;
	status HeadInsertCreateLS();
	status RearInsertCreateLS();
};

/*************************单循环链表*****************************/
class LoopLinkedList
{
public:
	LoopLinkedList();
	~LoopLinkedList();
	void CreateLLS();
	void ShowWindow();
	status AddNode(int index);
	status DeleteNode(int index);
	status FindNodeByIndex(int index);
	void Traverse();
private:
	LinkedNode * rear;
	int length;
};

/*************************双向链表*****************************/
typedef struct TWNode
{
	int data;
	TWNode *prior;
	TWNode *next;

}TWNode;

class TwoWayLinkedList
{
public:
	TwoWayLinkedList();
	~TwoWayLinkedList();
	void CreateTWLS();
	void ShowWindow();
	status AddNode(int index);
	status DeleteNode(int index);
	status FindNodeByIndex(int index);
	void Traverse();
private:
	TWNode * head;
	int length;
	void PositiveTraverse();
	void NegativeTraverse();
};

/*************************静态链表*****************************/
typedef struct StaticNode
{
	int data;
	int cur;
}StaticNode;
class StaticLinkedList {
public:
	StaticLinkedList();
	~StaticLinkedList();
	void InitializeStaticLs();
	void ShowWindow();
	status AddNode(int index);
	status DeleteNode(int index);
	status FindNodeByIndex(int index);
	void Traverse();
	int MallocSL();
	void FreeSLNode(int index);
private:
	StaticNode StaticList[MAXSPACE];
	int length;
};

