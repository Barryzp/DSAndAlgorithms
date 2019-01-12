#include "RSList.h"

LoopLinkedList::LoopLinkedList()
{
	LinkedNode * initialNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	initialNode->next = NULL;
	this->rear = initialNode;
	length = 0;
}

LoopLinkedList::~LoopLinkedList()
{

}

void LoopLinkedList::CreateLLS()
{
	cout << "������ѭ������ing......" << endl;

	LinkedNode *localHead = this->rear;
	int nodeNum = 0;
	cout << "�����봴��������Ľڵ���������ͣ���" << endl;
	cin >> nodeNum;

	for (int index = 0; index < nodeNum; index++)
	{
		LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
		int tempData = 0;
		cout << "�������" << index + 1 << "���ڵ��ֵ�����ͣ���" << endl;
		cin >> tempData;
		newNode->data = tempData;

		//������Ҫ�ж��ǲ��ǵ�һ���ռ���Ľڵ�
		if (localHead->next==NULL)
		{
			localHead->next = newNode;
		}
		else
		{
			this->rear->next = newNode;
		}
		newNode->next = localHead;
		this->rear = newNode;

		this->length++;
	}
}

void LoopLinkedList::ShowWindow() 
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

void LoopLinkedList::Traverse()
{
	if (this->rear->next==NULL)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	LinkedNode * temper = this->rear->next->next;
	int counter = 1;

	while (temper !=this->rear->next)
	{
		cout << "��" << counter << "���ڵ�����Ϊ��" << temper->data << endl;
		temper = temper->next;
		counter++;
	}
}

status LoopLinkedList::AddNode(int index)
{
	LinkedNode *tempPtr = this->rear->next;
	LinkedNode *temp;
	LinkedNode *head = this->rear->next;
	LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	int counter = 0;
	int data = 0;
	if (index > this->length|| index<=0)
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

	if (index==this->length)
	{
		tempPtr->next = newNode;
		newNode->next = head;
		this->rear = newNode;
	}
	else
	{
		tempPtr->next = newNode;
		newNode->next = temp;
	}

	this->length++;
	return SUCCESS;
}

status LoopLinkedList::DeleteNode(int index)
{
	LinkedNode *tempPtr = this->rear->next;
	LinkedNode *head=tempPtr;
	LinkedNode *temp;
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

	if (index==this->length)
	{
		tempPtr->next = head;
		this->rear = tempPtr;
	}
	else
	{
		tempPtr->next = tempPtr->next->next;
	}
	this->length--;
	free(temp);
	return SUCCESS;
}

status LoopLinkedList::FindNodeByIndex(int index)
{
	LinkedNode *tempPtr = this->rear->next;
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