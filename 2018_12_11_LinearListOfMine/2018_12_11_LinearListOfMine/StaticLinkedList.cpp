#include "RSList.h"
StaticLinkedList::StaticLinkedList()
{
	for (int index=0;index<MAXSPACE-1;index++)
	{
		this->StaticList[index].cur = index + 1;
	}
	this->StaticList[MAXSPACE - 1].cur = 1;
	this->length = 0;
}

StaticLinkedList::~StaticLinkedList()
{

}

void StaticLinkedList::InitializeStaticLs()
{
	int initialNum;
	int lastIndex = 0;
	cout<<"请输入初始的节点个数："<<endl;
	cin >> initialNum;

	for (int index=0;index<initialNum;index++)
	{
		int spareIndex = MallocSL();
		if (spareIndex<=0)
		{
			cout<<"无剩余空间！"<<endl;
			return;
		}

		this->StaticList[spareIndex].data = index + 1;
		lastIndex = spareIndex;
		this->length++;
	}
	this->StaticList[lastIndex].cur = 0;
}

void StaticLinkedList::ShowWindow()
{
	int selectIndex = 0;
	int inputIndex = -1;
	string data = "";
	Node node;
	while (true)
	{
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到单链表中" << endl;
		cout << "2.删除指定元素" << endl;
		cout << "3.获取指定节点数据" << endl;
		cout << "4.遍历静态链表" << endl;
		cout << "5.查看长度，剩余空间" << endl;
		cout << "6.退出" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			AddNode(inputIndex);
			break;
		case 2:
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			DeleteNode(inputIndex);
			break;
		case 3:
			cout << "请输入索引：" << endl;
			cin >> inputIndex;
			FindNodeByIndex(inputIndex);
			break;
		case 4:
			Traverse();
			break;
		case 5:
			cout << "Length: " << this->length << endl;
			cout << "Spare space: " << (MAXSPACE-(this->length)-2) << endl;
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}


status StaticLinkedList::AddNode(int index)
{
	int cursor = this->StaticList[MAXSPACE - 1].cur;
	int counter = 1;
	int mallocIndex = -1;
	int data;

	cout << "请输入数据：" << endl;
	cin >> data;
	if (index>=MAXSPACE-2)
	{
		return NO_MORE_SPACE;
	}

	while (counter<index)
	{
		cursor = this->StaticList[cursor].cur;
		counter++;
	}
	mallocIndex = MallocSL();
	this->StaticList[mallocIndex].data = data;
	int temp = this->StaticList[cursor].cur;
	this->StaticList[cursor].cur = mallocIndex;
	this->StaticList[mallocIndex].cur = temp;
	this->length++;

	return SUCCESS;
}

status StaticLinkedList::DeleteNode(int index)
{
	int cursor = MAXSPACE - 1;
	int counter = 1;

	if (index >= MAXSPACE - 2)
	{
		return NO_MORE_SPACE;
	}

	while (counter < index-1)
	{
		cursor = this->StaticList[cursor].cur;
		counter++;
	}
	int temp = this->StaticList[cursor].cur;
	int nextOne = this->StaticList[temp].cur;
	this->StaticList[cursor].cur = nextOne;
	FreeSLNode(temp);
	this->length--;

	return SUCCESS;
}

status StaticLinkedList::FindNodeByIndex(int index)
{
	int cursor = this->StaticList[MAXSPACE - 1].cur;
	int counter = 1;

	if (index>this->length)
	{
		return ERROR_INDEX_OVER;
	}
	if (index >= MAXSPACE - 2)
	{
		return NO_MORE_SPACE;
	}

	while (counter < index)
	{
		cursor = this->StaticList[cursor].cur;
		counter++;
	}
	cout <<"数据为：" <<this->StaticList[cursor].data << endl;

	return SUCCESS;
}

void StaticLinkedList::Traverse()
{
	int startIndex = this->StaticList[MAXSPACE - 1].cur;
	int counter = 1;
	while (startIndex != 0)
	{
		cout << "第" << counter << "个节点数据为：" << this->StaticList[startIndex].data << endl;
		startIndex = this->StaticList[startIndex].cur;
		counter++;
	}
}

int StaticLinkedList::MallocSL()
{
	if (this->StaticList[0].cur==MAXSPACE-1)
	{
		return NO_MORE_SPACE;
	}

	int nextCursor = this->StaticList[0].cur;
	this->StaticList[0].cur = this->StaticList[nextCursor].cur;
	return nextCursor;
}

void StaticLinkedList::FreeSLNode(int index)
{
	int temp = this->StaticList[0].cur;
	this->StaticList[0].cur = index;
	this->StaticList[index].cur = temp;
}