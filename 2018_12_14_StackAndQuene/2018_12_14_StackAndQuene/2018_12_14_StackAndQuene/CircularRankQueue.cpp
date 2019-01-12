#include "Tools.h"

CircularRankQueue::CircularRankQueue()
{
	this->front = 0;
	this->rear = 0;
	this->length = 0;
}

CircularRankQueue::~CircularRankQueue()
{

}

void CircularRankQueue::InitialQueue()
{
	int initialNum = 0;
	cout << "请输入初始化的队列(顺序存储)元素个数：" << endl;
	cin >> initialNum;

	for (int index=0;index<initialNum;index++)
	{
		this->EnterQueue(index + 1);
	}
}

void CircularRankQueue::ShowWindow()
{
	int selectIndex = 0;
	int data;
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
			cout << "请输入数据：" << endl;
			cin >> data;
			this->EnterQueue(data);
			break;
		case 2:
			this->OutQueue();
			break;
		case 3:
			cout << "栈顶数据为：" << this->GetElement() << endl;
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
			cout << "请输入正确的序号，小老弟。" << endl;
			break;
		}
	}
}

void CircularRankQueue::EnterQueue(int data)
{
	if (this->IsFull())
	{
		cout << "队列已满！" << endl;
		return;
	}

	this->queue[this->rear] = data;
	this->rear = (this->rear + 1) % QUEUELENGTH;
	this->length++;
}

void CircularRankQueue::OutQueue()
{
	if (this->IsEmpty())
	{
		cout << "队列为空！" << endl;
		return;
	}

	this->front = (this->front+1) % QUEUELENGTH;
	this->length--;
}

int CircularRankQueue::GetElement()
{
	if (this->IsEmpty())
	{
		cout << "队列为空！" << endl;
		return -9999;
	}

	return this->queue[this->front];
}

void CircularRankQueue::Traverse()
{
	int tempFront = this->front;
	int tempRear = this->rear;
	int counter = 1;
	while (tempFront!=tempRear)
	{
		cout <<"第"<<counter <<"个队列元素值为" <<this->queue[tempFront]<< endl;
		tempFront=(tempFront+1)%QUEUELENGTH;
		counter++;
	}
}

bool CircularRankQueue::IsEmpty()
{
	if (this->front==this->rear)
	{
		return true;
	}
	return false;
}

bool CircularRankQueue::IsFull()
{
	if ((this->rear+1)%QUEUELENGTH==this->front)
	{
		return true;
	}
	return false;
}