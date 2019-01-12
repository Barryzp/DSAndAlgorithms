#include "RSList.h"
RankedStrorageList::RankedStrorageList(Node *ls,int len)
{
	//initialize
	this->RSList = ls;
	this->length = len;
	this->space = MAXSIZE;
}


RankedStrorageList::~RankedStrorageList()
{
	free(this->RSList);
}

void RankedStrorageList::ShowWindow()
{
	int selectIndex = 0;
	int inputIndex = -1;
	string data = "";
	Node node;
	while (true)
	{
		cout << "ѡ�����ָ��������" << endl;
		cout << "1.���Ԫ�ص�˳�����" << endl;
		cout << "2.ɾ��Ԫ�ص�˳���" << endl;
		cout << "3.��ȡָ���ڵ�����" << endl;
		cout << "4.����˳���" << endl;
		cout << "5.�鿴����" << endl;
		cout << "6.�˳�" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			cout << "���������ݣ�" << endl;
			cin >> data;
			node.content = data;
			node.index = rand() / 10;
			AddItemByIndex(node);
			break;
		case 2:
			cout << "������������" << endl;
			cin >> inputIndex;
			DeleteItemByIndex(inputIndex);
			break;
		case 3:
			cout << "������������" << endl;
			cin >> inputIndex;
			node = GetItemByIndex(inputIndex);
			cout << "����Ϊ��" << node.content << endl;
			break;
		case 4:
			ReverseArray();
			break;
		case 5:
			cout<<"Length: "<<this->length<<endl;
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}

Node RankedStrorageList::GetItemByIndex(int index)
{
	if (index > this->length || index <= 0)
	{
		Node node;
		node.content = "ERROR:index overstep boundary.";
		node.index = -1;
		return node;
	}

	return this->RSList[index - 1];
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
	if (index == this->length)
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

status RankedStrorageList::AddItemByIndex(Node item)
{
	int index = this->length;

	if ((index+1) > space)
	{
		IncreaseSpace();
	}

	if (index <= 0)
	{
		return ERROR_INDEX_OVER;
	}

	Node node = this->RSList[index - 1];

	if (index == this->length + 1)
	{
		this->RSList[index - 1] = item;
	}
	else
	{
		int counter = this->length - 1;
		for (; counter > index - 1; counter--)
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

//��Щ���⣬���Ǳ���ô��
void RankedStrorageList::IncreaseSpace()
{
	int newSpace = (this->space) + MAXSIZE;
	Node* list = new Node[newSpace];
	Node* loc = this->RSList;

	int counter = 0;
	for (counter = 0; counter < length - 1; counter++)
	{
		list[counter].content = RSList[counter].content;
		cout << "list[counter].content:" << list[counter].content << endl;
	}
	this->RSList = list;
	this->space = newSpace;
}

void RankedStrorageList::ReverseArray()
{
	int index = 0;
	for (; index < this->length; index++)
	{
		cout << "index:" << index << endl;
		cout << "content:" << RSList[index].content << endl;
	}
}