#include "BTree.h"

BTreeC::BTreeC()
{
	this->count = 0;
	this->CreateBTree();
}

BTreeC::~BTreeC()
{

}

void BTreeC::CreateBTree()
{
	char inputStr[MAXINPUT];
	Counter = 0;
	cout << "按照先序序列输入二叉树字符串，'$'为空：" << endl;
	cin >> inputStr;
	//int length = strlen(inputStr);
	this->InitialTreeNode(&this->root, inputStr);

	cout << "完事儿！" << endl;
}

void BTreeC::InitialTreeNode(BNTree *tree, char* data)
{
	if (data[Counter]=='$')
	{
		(*tree) = NULL;
		Counter++;
		return;
	}
	else
	{
		*tree = (BNTree)malloc(sizeof(BTNode));
		(*tree)->data = data[Counter];
		Counter++;
		this->count++;
		InitialTreeNode(&(*tree)->leftChild,data);
		InitialTreeNode(&(*tree)->rightChild, data);
	}
}

void BTreeC::Traverse()
{
	int selectNum = 0;
	cout << "请输入遍历类型：" << endl;
	cout << "1.先序，2.中序，3.后序：" << endl;
	cin >> selectNum;

	switch (selectNum)
	{
	case 1:
		this->PreOrder(root);
		break;
	case 2:
		this->InOrder(root);
		break;
	case 3:
		this->LastOrder(root);
		break;
	default:
		cout << "请输入正确的序号！" << endl;
		break;
	}
}

void BTreeC::PreOrder(BNTree tree)
{
	if (tree==NULL)
	{
		return;
	}
	else
	{
		cout << tree->data << endl;
		this->PreOrder(tree->leftChild);
		this->PreOrder(tree->rightChild);
	}
}

void BTreeC::InOrder(BNTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		this->InOrder(tree->leftChild);
		cout << tree->data << endl;
		this->InOrder(tree->rightChild);
	}
}

void BTreeC::LastOrder(BNTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		this->LastOrder(tree->leftChild);
		this->LastOrder(tree->rightChild);
		cout << tree->data << endl;
	}
}