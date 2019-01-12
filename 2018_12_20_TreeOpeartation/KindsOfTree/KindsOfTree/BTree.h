#pragma once
#include <iostream>
#include <string.h>
using namespace std;

#define MAXINPUT 200

static int Counter;

typedef struct BTNode
{
	char data;
	BTNode *leftChild;
	BTNode *rightChild;
}BTNode,*BNTree;

class BTreeC
{
public:
	BTreeC();
	~BTreeC();
	void CreateBTree();
	void Traverse();
private:
	BNTree root;
	int count;

	void PreOrder(BNTree tree);
	void InOrder(BNTree tree);
	void LastOrder(BNTree tree);
	void InitialTreeNode(BNTree *tree, char* data);
};


typedef enum Tag
{
	Link,Thread
}Tag;

typedef struct BTNode_Thread
{
	Tag lTag,rTag;
	char data;
	BTNode_Thread *leftChild;
	BTNode_Thread *rightChild;
}BTNode_Thread, *BNTree_Thread;

static BNTree_Thread Pre;

class BTreeC_Tread
{
public:
	BTreeC_Tread();
	~BTreeC_Tread();
	void CreateBTree_Tread();
	void Traverse_InOrderTread();
private:
	BNTree_Thread root;
	BNTree_Thread head;
	int count;
	void InitialTreeNode(BNTree_Thread *tree, char* data);
	void Test_PreOrderTrav(BNTree_Thread root);
	void CreateThread(BNTree_Thread tree);
};