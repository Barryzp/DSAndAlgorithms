#include "stdafx.h"
#include "MyList.h"
RankedStrorageList::RankedStrorageList()
{
	//initialize
	this->RSList = (Node *)malloc(sizeof(Node)*MAXSIZE);
	this->space = MAXSIZE;
}


RankedStrorageList::~RankedStrorageList()
{
	free(this->RSList);
}

void RankedStrorageList::ShowWindow()
{
	int selectIndex=0;
	int inputIndex = -1;
	string data = "";
	Node node;
	while (selectIndex!=5)
	{
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到顺序表中" << endl;
		cout << "2.删除元素到顺序表" << endl;
		cout << "3.获取指定节点数据" << endl;
		cout << "4.遍历顺序表" << endl;
		cout << "5.退出" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			
			cout << "请输入数据：" << endl;
			cin >> data;
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			node.content = data;
			node.index = rand() / 10;
			AddItemByIndex(inputIndex, node);
			break;
		case 2:
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			DeleteItemByIndex(inputIndex);
			break;
		case 3:
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			node = GetItemByIndex(inputIndex);
			cout << "内容为：" << node.content << endl;
			break;
		case 4:
			ReverseArray();
			break;
		default:
			break;
		}
	}
}

Node RankedStrorageList::GetItemByIndex(int index)
{
	if (index>this->length||index<=0)
	{
		Node node;
		node.content = "ERROR:index overstep boundary.";
		node.index = -1;
		return node;
	}

	return this->RSList[index-1];
}

Node RankedStrorageList::DeleteItemByIndex(int index)
{
	if (index > this->length || index <= 0)
	{
		Node node;
		node.content = "ERROR:index overstep boundary.";
		node.index = -1;
		return node;
	}

	Node node = this->RSList[index - 1];
	if (index==this->length)
	{
	}
	else
	{
		int counter = index - 1;
		for (; counter <= this->length - 1; counter++)
		{
			this->RSList[counter] = this->RSList[counter + 1];
		}
	}
	this->length--;

	return node;
}

status RankedStrorageList::AddItemByIndex(int index, Node item)
{
	if (index > this->length || index <= 0)
	{
		return ERROR_INDEX_OVER;
	}

	Node node = this->RSList[index - 1];
	
	if (index>space)
	{
		IncreaseSpace();
	}
	
	if (index == this->length+1)
	{
		this->RSList[index - 1] = item;
	}
	else
	{
		int counter = this->length-1;
		for (;counter>index-1;counter--)
		{
			this->RSList[counter + 1] = this->RSList[counter];
		}
		this->RSList[counter] = item;
	}
	this->length++;

	return SUCCESS;
}

int RankedStrorageList::GetLength()
{
	return this->length;
}

void RankedStrorageList::IncreaseSpace()
{
	int newSpace = (this->space) + MAXSIZE;
	Node* list=(Node *)malloc(newSpace*sizeof(Node));
	Node* loc = this->RSList;

	int counter = 0;
	for (counter= 0; counter < length-1; counter++)
	{
		list[counter].content = RSList[counter].content;
	}
	this->RSList = list;
	this->space = newSpace;

	//free old list space.
	free(loc);
}

void RankedStrorageList::ReverseArray()
{
	int index = 0;
	for (;index<this->length;index++)
	{
		cout << "index:" <<index<< endl;
		cout << "content:" << RSList[index].content << endl;
	}
}
