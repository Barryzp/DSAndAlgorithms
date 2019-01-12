#include "Tools.h"
LinkedQueue::LinkedQueue()
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	this->front = newNode;
	this->rear = newNode;
	this->length = 0;
}

LinkedQueue::~LinkedQueue()
{

}

void LinkedQueue::InitialQueue()
{
	int initialNum = 0;
	cout << "请输入初始化的队列(链式存储)元素个数：" << endl;
	cin >> initialNum;

	for (int index=0;index<initialNum;index++)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = index + 65;
		newNode->next = NULL;
		this->EnterQueue(newNode);
	}
}

void LinkedQueue::ShowWindow()
{
	int selectIndex = 0;
	char data;
	while (true)
	{
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到队列中" << endl;
		cout << "2.删除元素" << endl;
		cout << "3.获取队列数据" << endl;
		cout << "4.遍历队列" << endl;
		cout << "5.查看长度" << endl;
		cout << "6.退出" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
		{
			cout << "请输入数据：" << endl;
			cin >> data;
			Node *node = (Node *)malloc(sizeof(Node));
			node->data = data;
			node->next = NULL;
			this->EnterQueue(node);
			break;
		}
		case 2:
			this->OutQueue();
			break;
		case 3:
		{
			Node * node = this->GetElement();
			cout << "栈顶数据为：" << node->data << endl;
			break;
		}
		case 4:
			Traverse();
			break;
		case 5:
			cout << "Length: " << this->length << endl;
			break;
		case 6:
			return;
		default:
			cout << "请输入正确的序号，小老弟。" << endl;
			break;
		}
	}
}

void LinkedQueue::EnterQueue(Node* data)
{
	this->rear->next = data;
	this->rear = data;
	this->length++;
}

void LinkedQueue::OutQueue()
{
	Node *temp = this->front->next;
	this->front->next = temp->next;
	this->length--;
	free(temp);
}

bool LinkedQueue::IsEmpty()
{
	if (this->front==this->rear)
	{
		return true;
	}
	return false;
}

Node* LinkedQueue::GetElement()
{
	if (this->IsEmpty())
	{
		cout << "队列为空，兄弟！" << endl;
		return NULL;
	}
	return this->front->next;
}

void LinkedQueue::Traverse()
{
	Node* tempFront = this->front->next;
	int counter = 1;
	while (tempFront != NULL)
	{
		cout << "第" << counter << "个队列元素值为" << tempFront->data << endl;
		tempFront = tempFront->next;
		counter++;
	}
}