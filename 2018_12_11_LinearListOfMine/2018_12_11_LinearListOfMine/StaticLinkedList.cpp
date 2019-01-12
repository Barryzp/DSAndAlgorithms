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
	cout<<"�������ʼ�Ľڵ������"<<endl;
	cin >> initialNum;

	for (int index=0;index<initialNum;index++)
	{
		int spareIndex = MallocSL();
		if (spareIndex<=0)
		{
			cout<<"��ʣ��ռ䣡"<<endl;
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
		cout << "ѡ�����ָ��������" << endl;
		cout << "1.���Ԫ�ص���������" << endl;
		cout << "2.ɾ��ָ��Ԫ��" << endl;
		cout << "3.��ȡָ���ڵ�����" << endl;
		cout << "4.������̬����" << endl;
		cout << "5.�鿴���ȣ�ʣ��ռ�" << endl;
		cout << "6.�˳�" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			cout << "������������" << endl;
			cin >> inputIndex;
			AddNode(inputIndex);
			break;
		case 2:
			cout << "������������" << endl;
			cin >> inputIndex;
			DeleteNode(inputIndex);
			break;
		case 3:
			cout << "������������" << endl;
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

	cout << "���������ݣ�" << endl;
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
	cout <<"����Ϊ��" <<this->StaticList[cursor].data << endl;

	return SUCCESS;
}

void StaticLinkedList::Traverse()
{
	int startIndex = this->StaticList[MAXSPACE - 1].cur;
	int counter = 1;
	while (startIndex != 0)
	{
		cout << "��" << counter << "���ڵ�����Ϊ��" << this->StaticList[startIndex].data << endl;
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