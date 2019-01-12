#include "RSList.h"
TwoWayLinkedList::TwoWayLinkedList()
{
	TWNode *initialNode = (TWNode *)malloc(sizeof(TWNode));
	this->head = initialNode;
	initialNode->next = initialNode;
	initialNode->prior = initialNode;
	this->length = 0;
}

TwoWayLinkedList::~TwoWayLinkedList()
{

}

void TwoWayLinkedList::CreateTWLS()
{
	cout << "����˫������β�巨��ing......" << endl;

	TWNode *localHead = this->head;
	int nodeNum = 0;
	cout << "�����봴��������Ľڵ���������ͣ���" << endl;
	cin >> nodeNum;

	for (int index = 0; index < nodeNum; index++)
	{
		TWNode *newNode = (TWNode *)malloc(sizeof(TWNode));
		int tempData = 0;
		cout << "�������" << index + 1 << "���ڵ��ֵ�����ͣ���" << endl;
		cin >> tempData;
		newNode->data = tempData;

		localHead->next = newNode;
		newNode->prior = localHead;
		newNode->next = this->head;
		this->head->prior = newNode;
		localHead = newNode;

		this->length++;
	}
}

void TwoWayLinkedList::ShowWindow()
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
		cout << "4.����������" << endl;
		cout << "5.�鿴����" << endl;
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
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}

void TwoWayLinkedList::Traverse()
{
	int selectNum = 0;
	cout << "1.����ʹ��->next:" << endl;
	cout << "2.����ʹ��->prior:" << endl;
	cin >> selectNum;
	if (selectNum==1)
	{
		PositiveTraverse();
	}
	else if(selectNum==2)
	{
		NegativeTraverse();
	}
}

void TwoWayLinkedList::PositiveTraverse()
{
	if (this->head->next == this->head->prior)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	TWNode * temper = this->head->next;
	int counter = 1;

	while (temper != this->head)
	{
		cout << "��" << counter << "���ڵ�����Ϊ��" << temper->data << endl;
		temper = temper->next;
		counter++;
	}
}

void TwoWayLinkedList::NegativeTraverse()
{
	if (this->head->next == this->head->prior)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	TWNode * temper = this->head->prior;
	int counter = 1;

	while (temper != this->head)
	{
		cout << "��" << counter << "���ڵ�����Ϊ��" << temper->data << endl;
		temper = temper->prior;
		counter++;
	}
}

status TwoWayLinkedList::AddNode(int index)
{
	TWNode *tempPtr = this->head;
	TWNode *temp;
	TWNode *newNode = (TWNode *)malloc(sizeof(TWNode));
	int counter = 0;
	int data = 0;
	if (index > this->length || index <= 0)
	{
		cout << "������Ϸ���������" << endl;
		return INVAILD_INPUT;
	}

	cout << "���������ݣ����ͣ���" << endl;
	cin >> data;
	newNode->data = data;
	newNode->next = NULL;

	while (counter < index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	temp = tempPtr->next;
	tempPtr->next = newNode;
	newNode->prior = tempPtr;
	temp->prior = newNode;
	newNode->next = temp;

	this->length++;
	return SUCCESS;
}

status TwoWayLinkedList::DeleteNode(int index)
{
	TWNode *tempPtr = this->head;
	TWNode *temp;
	int counter = 1;
	if (index > this->length)
	{
		cout << "������Ϸ���������" << endl;
		return INVAILD_INPUT;
	}

	while (counter < index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	temp = tempPtr->next;

	temp->next->prior = tempPtr;
	tempPtr->next = temp->next;
	this->length--;
	free(temp);
	return SUCCESS;
}

status TwoWayLinkedList::FindNodeByIndex(int index)
{
	TWNode *tempPtr = this->head;
	int counter = 1;
	if (index > this->length)
	{
		cout << "������Ϸ���������" << endl;
		return INVAILD_INPUT;
	}

	tempPtr = tempPtr->next;
	while (counter < index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	cout << "ֵΪ��" << tempPtr->data << endl;
	return SUCCESS;
}