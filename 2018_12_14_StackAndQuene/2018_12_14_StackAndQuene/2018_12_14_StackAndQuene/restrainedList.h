#pragma once
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
#define STACKLENGTH 20
#define EXPRESSIONLENGTH 45
#define QUEUELENGTH 6

/*1.**********************ջ��˳��洢*********************************/
class RankedStorageStack
{
public:
	RankedStorageStack();
	~RankedStorageStack();

	void InitialRSStack();
	void ShowWindow();
	int GetElement();
	void PushElement();
	void PopElement();
	void Traverse();
private:
	int stack[STACKLENGTH];
	int top;
	int length;
};

/*2.**********************ջ����ʽ�洢*********************************/
typedef struct Node
{
	char data;
	Node *next;
}Node;

class LinkedStack
{
public:
	LinkedStack();
	~LinkedStack();

	void InitialStack();
	//void InitialStack(char str[]);
	void ShowWindow();
	Node* GetElement();
	void PushElement();
	void PushElement(char c);
	void PopElement();
	void Traverse();
private:
	Node * front;
	int length;
};

/*3.**********************ѭ�����е�˳��洢*********************************/
class CircularRankQueue
{
public:
	CircularRankQueue();
	~CircularRankQueue();

	void InitialQueue();
	void ShowWindow();
	void EnterQueue(int data);
	void OutQueue();
	int GetElement();
	bool IsEmpty();
	bool IsFull();
	void Traverse();
private:
	int queue[QUEUELENGTH];
	int front;
	int rear;
	int length;
};

/*4.**********************���е���ʽ�洢*********************************/
class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();

	void InitialQueue();
	void ShowWindow();
	void EnterQueue(Node* data);
	void OutQueue();
	Node* GetElement();
	bool IsEmpty();
	void Traverse();
private:
	Node* front;
	Node* rear;
	int length;
};