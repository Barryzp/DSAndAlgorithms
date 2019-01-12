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
	cout << "�������ʼ���Ķ���(˳��洢)Ԫ�ظ�����" << endl;
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
		cout << "ѡ�����ָ��������" << endl;
		cout << "1.���Ԫ�ص�������" << endl;
		cout << "2.ɾ��Ԫ��" << endl;
		cout << "3.��ȡ��������" << endl;
		cout << "4.��������" << endl;
		cout << "5.�鿴����" << endl;
		cout << "6.�˳�" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			cout << "���������ݣ�" << endl;
			cin >> data;
			this->EnterQueue(data);
			break;
		case 2:
			this->OutQueue();
			break;
		case 3:
			cout << "ջ������Ϊ��" << this->GetElement() << endl;
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
			cout << "��������ȷ����ţ�С�ϵܡ�" << endl;
			break;
		}
	}
}

void CircularRankQueue::EnterQueue(int data)
{
	if (this->IsFull())
	{
		cout << "����������" << endl;
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
		cout << "����Ϊ�գ�" << endl;
		return;
	}

	this->front = (this->front+1) % QUEUELENGTH;
	this->length--;
}

int CircularRankQueue::GetElement()
{
	if (this->IsEmpty())
	{
		cout << "����Ϊ�գ�" << endl;
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
		cout <<"��"<<counter <<"������Ԫ��ֵΪ" <<this->queue[tempFront]<< endl;
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