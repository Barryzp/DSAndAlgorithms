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
	cout << "�������ʼ���Ķ���(��ʽ�洢)Ԫ�ظ�����" << endl;
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
		{
			cout << "���������ݣ�" << endl;
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
			cout << "ջ������Ϊ��" << node->data << endl;
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
			cout << "��������ȷ����ţ�С�ϵܡ�" << endl;
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
		cout << "����Ϊ�գ��ֵܣ�" << endl;
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
		cout << "��" << counter << "������Ԫ��ֵΪ" << tempFront->data << endl;
		tempFront = tempFront->next;
		counter++;
	}
}