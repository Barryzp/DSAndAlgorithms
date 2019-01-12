#include "BTree.h"
BTreeC_Tread::BTreeC_Tread()
{
	Pre = (BNTree_Thread)malloc(sizeof(BTNode_Thread));
	Pre->leftChild = NULL;
	Pre->rightChild = NULL;
	this->count = 0;
	this->head = (BNTree_Thread)malloc(sizeof(BTNode_Thread));
	this->head->leftChild = NULL;
	this->head->rightChild = NULL;
	this->CreateBTree_Tread();
}

BTreeC_Tread::~BTreeC_Tread()
{

}

void BTreeC_Tread::CreateBTree_Tread()
{
	char inputStr[MAXINPUT];
	Counter = 0;
	cout << "按照先序序列输入二叉树字符串，'$'为空：" << endl;
	cin >> inputStr;
	//int length = strlen(inputStr);
	this->InitialTreeNode(&this->root, inputStr);
	this->head->lTag = Link;
	this->head->leftChild = this->root;
	cout << "完事儿！" << endl;
	cout << "线索化！" << endl;
	Counter = 0;
	this->CreateThread(root);
	cout << "完事儿！" << Counter << endl;
}

void BTreeC_Tread::InitialTreeNode(BNTree_Thread *tree, char* data)
{
	if (data[Counter] == '$')
	{
		(*tree) = NULL;
		Counter++;
		return;
	}
	else
	{
		*tree = (BNTree_Thread)malloc(sizeof(BTNode_Thread));
		(*tree)->data = data[Counter];
		Counter++;
		this->count++;
		InitialTreeNode(&(*tree)->leftChild, data);
		InitialTreeNode(&(*tree)->rightChild, data);

		if ((*tree)->leftChild!=NULL)
		{
			(*tree)->lTag =Link;
		}
		else
		{
			(*tree)->lTag = Thread;
		}
		if ((*tree)->rightChild != NULL)
		{
			(*tree)->rTag = Link;
		}
		else
		{
			(*tree)->rTag = Thread;
		}
	}
}

void BTreeC_Tread::CreateThread(BNTree_Thread tree)
{
	if (!tree)
	{
		return;
	}
	else
	{
		CreateThread(tree->leftChild);
		if (!tree->leftChild)
		{
			tree->leftChild = Pre;
		}

		if (!Pre->rightChild)
		{
			Pre->rightChild = tree;
		}
		Pre = tree;
		Counter++;
		CreateThread(tree->rightChild);
		if (Counter==1)
		{
			tree->leftChild = this->head;
		}
		if (Counter==this->count&&this->head->rightChild==NULL)
		{
			tree->rightChild = this->head;
			this->head->rightChild = tree;
			this->head->rTag = Thread;
		}
	}
}

void BTreeC_Tread::Traverse_InOrderTread()
{
	BNTree_Thread rt = this->head->leftChild;
	while (rt!=head)
	{
		while (rt->lTag==Link)
			rt = rt->leftChild;
		cout << rt->data;
		while (rt->rTag == Thread && rt->rightChild != head)
		{
			rt = rt->rightChild;
			cout << rt->data;
		}
		rt = rt->rightChild;
	}
}

void BTreeC_Tread::Test_PreOrderTrav(BNTree_Thread root)
{
	if (root==NULL)
	{
		return;
	}

	cout << "lTag = " << root->lTag<< " rTag = "<<root->rTag<<"   data = "<<root->data<<endl;
	Test_PreOrderTrav(root->leftChild);
	Test_PreOrderTrav(root->rightChild);
}