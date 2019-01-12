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
	cout<<"输入创建表的方法："<<endl;
	cout << "1.头插法" << endl;
	cout << "2.尾插法" << endl;
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

void LinkedList::Traverse()
{
	LinkedNode* temper = head->next;

	if (!head->next)
	{
		cout << "链表为空！" << endl;
		return;
	}

	int counter = 1;
	while (temper)
	{
		cout << "第" << counter << "个节点数据为：" << temper->data<<endl;
		temper = temper->next;
		counter++;
	}
}

status LinkedList::HeadInsertCreateLS()
{
	LinkedNode *localHead = this->head;
	int nodeNum = 0;
	cout << "请输入创建的链表的节点个数（整型）：" << endl;
	cin >> nodeNum;

	for (int index = 0; index < nodeNum; index++)
	{
		LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
		int tempData = 0;
		cout << "请输入第" << index + 1 << "个节点的值（整型）：" << endl;
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
	cout << "请输入创建的链表的节点个数（整型）：" << endl;
	cin >> nodeNum;

	for (int index = 0; index < nodeNum; index++)
	{
		LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
		int tempData = 0;
		cout << "请输入第" << index + 1 << "个节点的值（整型）：" << endl;
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
		cout << "请输入合法的索引！" << endl;
		return INVAILD_INPUT;
	}

	tempPtr = tempPtr->next;
	while (counter<index)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	cout << "值为：" << tempPtr->data << endl;
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
		cout << "请输入合法的索引！" << endl;
		return INVAILD_INPUT;
	}

	cout << "请输入数据（整型）：" << endl;
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
		cout << "请输入合法的索引！" << endl;
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
