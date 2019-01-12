#include "RSList.h"

LinkedList::LinkedList()
{
	LinkedNode *initialNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	head = initialNode;
	head->next = NULL;
	this->length = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::CreateLS()
{
	int selectNum = 0;
	cout<<"���봴����ķ�����"<<endl;
	cout << "1.ͷ�巨" << endl;
	cout << "2.β�巨" << endl;
	cin >> selectNum;

	switch (selectNum)
	{
	case 1:
		this->HeadInsertCreateLS();
		break;
	case 2:
		this->RearInsertCreateLS();
		break;
	default:
		break;
	}
}

void LinkedList::ShowWindow()
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

void LinkedList::Traverse()
{
	LinkedNode* temper = head->next;

	if (!head->next)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}

	int counter = 1;
	while (temper)
	{
		cout << "��" << counter << "���ڵ�����Ϊ��" << temper->data<<endl;
		temper = temper->next;
		counter++;
	}
}

status LinkedList::HeadInsertCreateLS()
{
	LinkedNode *localHead = this->head;
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
		newNode->next = NULL;
		LinkedNode *temp = localHead->next;
		localHead->next = newNode;
		newNode->next = temp;

		this->length++;
	}
	return SUCCESS;
}

status LinkedList::RearInsertCreateLS() 
{
	LinkedNode *localHead = this->head;
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
		newNode->next = NULL;
		localHead->next = newNode;
		localHead = newNode;

		this->length++;
	}
	return SUCCESS;
}

status LinkedList::FindNodeByIndex(int index)
{
	LinkedNode *tempPtr = this->head;
	int counter = 1;
	if (index>this->length)
	{
		cout << "������Ϸ���������" << endl;
		return INVAILD_INPUT;
	}

	tempPtr = tempPtr->next;
	while (counter<index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	cout << "ֵΪ��" << tempPtr->data << endl;
	return SUCCESS;
}

status LinkedList::AddNode(int index)
{
	LinkedNode *tempPtr = this->head;
	LinkedNode *temp;
	LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
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

	while (counter<index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	temp = tempPtr->next;
	tempPtr->next = newNode;
	newNode->next = temp;
	this->length++;
	return SUCCESS;
}

status LinkedList::DeleteNode(int index)
{
	LinkedNode *tempPtr = this->head;
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
	tempPtr->next = tempPtr->next->next;
	this->length--;
	free(temp);
	return SUCCESS;
}
