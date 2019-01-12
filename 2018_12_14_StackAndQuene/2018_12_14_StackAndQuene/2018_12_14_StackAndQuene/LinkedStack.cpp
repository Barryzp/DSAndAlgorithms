#include "restrainedList.h"
LinkedStack::LinkedStack()
{
	//��ջû��ͷ���
	this->front = NULL;
	this->length = 0;
}

LinkedStack::~LinkedStack()
{

}

void LinkedStack::InitialStack()
{
	Node *temp = this->front;
	int nodeNum = 0;
	cout << "������Ҫ���ɵĽڵ���Ŀ��" << endl;
	cin >> nodeNum;

	if (nodeNum<=0)
	{
		cout << "��������ɵĽڵ���Ŀ����С�ڻ����0��" << endl;
		return;
	}
	for (int index=0;index<nodeNum;index++)
	{
		Node* node = (Node *)malloc(sizeof(Node));
		node->data = index + 65;
		node->next = this->front;
		this->front = node;
		this->length++;
	}
}

/*void LinkedStack::InitialStack(char str[])
{
	int strLength = strlen(str);

	if (strLength<=2)
	{
		cout << "���ʽ����ͷ��С�ϵܣ�" << endl;
		return;
	}

	for (int index = 0; index < strLength; index++)
	{
	}
}*/

void LinkedStack::ShowWindow()
{
	int selectIndex = 0;
	string data = "";
	while (true)
	{
		cout << "ѡ�����ָ��������" << endl;
		cout << "1.���Ԫ�ص�ջ��" << endl;
		cout << "2.ɾ��Ԫ��" << endl;
		cout << "3.��ȡջ������" << endl;
		cout << "4.����ջ" << endl;
		cout << "5.�鿴����" << endl;
		cout << "6.�˳�" << endl;
		cin >> selectIndex;

		switch (selectIndex)
		{
		case 1:
			PushElement();
			break;
		case 2:
			PopElement();
			break;
		case 3:
			cout << "ջ������Ϊ��" << GetElement()->data << endl;
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

void LinkedStack::PopElement()
{
	if (this->front==NULL)
	{
		cout << "С�ϵܲ�����˼���ǿ�ջ��" << endl;
		return;
	}

	Node *deletedNode = this->front;
	this->front = this->front->next;
	free(deletedNode);
	this->length--;
}

void LinkedStack::PushElement()
{
	int data = 0;

	Node *newNode = (Node *)malloc(sizeof(Node));
	cout << "���������ݣ����ͣ���С�ϵܣ�" << endl;
	cin >> data;
	newNode->data = data;
	newNode->next = this->front;
	this->front = newNode;
	this->length++;
}

void LinkedStack::PushElement(char c)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = c;
	newNode->next = this->front;
	this->front = newNode;
	this->length++;
}

void LinkedStack::Traverse()
{
	Node *top=this->front;
	if (this->front==NULL)
	{
		cout << "С��֭��ջ���ˣ�" << endl;
		return;
	}

	int counter = 1;
	while (this->front!=NULL)
	{
		cout << "��" <<counter <<"������Ϊ" << this->front->data<< endl;
		this->front = this->front->next;
	}
	this->front = top;
}

Node* LinkedStack::GetElement()
{
	if (this->front==NULL)
	{
		cout << "ջ�ǿյģ��ևN��" << endl;
		return NULL;
	}
	
	return this->front;
}