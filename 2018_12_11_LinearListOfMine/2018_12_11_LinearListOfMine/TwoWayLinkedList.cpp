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
	cout << "创建双向链表（尾插法）ing......" << endl;

	TWNode *localHead = this->head;
	int nodeNum = 0;
	cout << "请输入创建的链表的节点个数（整型）：" << endl;
	cin >> nodeNum;

	for (int index = 0; index < nodeNum; index++)
	{
		TWNode *newNode = (TWNode *)malloc(sizeof(TWNode));
		int tempData = 0;
		cout << "请输入第" << index + 1 << "个节点的值（整型）：" << endl;
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
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到单链表中" << endl;
		cout << "2.删除指定元素" << endl;
		cout << "3.获取指定节点数据" << endl;
		cout << "4.遍历单链表" << endl;
		cout << "5.查看长度" << endl;
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
	cout << "1.正序使用->next:" << endl;
	cout << "2.倒序使用->prior:" << endl;
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
		cout << "链表为空！" << endl;
		return;
	}
	TWNode * temper = this->head->next;
	int counter = 1;

	while (temper != this->head)
	{
		cout << "第" << counter << "个节点数据为：" << temper->data << endl;
		temper = temper->next;
		counter++;
	}
}

void TwoWayLinkedList::NegativeTraverse()
{
	if (this->head->next == this->head->prior)
	{
		cout << "链表为空！" << endl;
		return;
	}
	TWNode * temper = this->head->prior;
	int counter = 1;

	while (temper != this->head)
	{
		cout << "第" << counter << "个节点数据为：" << temper->data << endl;
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
		cout << "请输入合法的索引！" << endl;
		return INVAILD_INPUT;
	}

	cout << "请输入数据（整型）：" << endl;
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
		cout << "请输入合法的索引！" << endl;
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
		cout << "请输入合法的索引！" << endl;
		return INVAILD_INPUT;
	}

	tempPtr = tempPtr->next;
	while (counter < index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	cout << "值为：" << tempPtr->data << endl;
	return SUCCESS;
}