#include "restrainedList.h"
RankedStorageStack::RankedStorageStack()
{
	this->top = -1;
	this->length = 0;
}

RankedStorageStack::~RankedStorageStack()
{

}

void RankedStorageStack::InitialRSStack()
{
	int initialNum=0;
	cout << "�������ʼ����ջԪ�ظ�����" << endl;
	cin >> initialNum;

	for (int index = 0; index < initialNum; index++)
	{
		this->top++;
		this->stack[top] = index + 1;
		this->length++;
	}
}

void RankedStorageStack::ShowWindow()
{
	int selectIndex = 0;
	int inputIndex = -1;
	string data = "";
	while (true)
	{
		cout << "ѡ�����ָ��������" << endl;
		cout << "1.���Ԫ�ص�ջ��" << endl;
		cout << "2.ɾ��Ԫ��" << endl;
		cout << "3.��ȡջ������" << endl;
		cout << "4.������ݲ�����ջ" << endl;
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
			cout<<"ջ������Ϊ��"<<GetElement()<<endl;
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

int RankedStorageStack::GetElement()
{
	if (this->top==-1)
	{
		cout << "��ջ��С��ƣ�" << endl;
		return -999;
	}

	return this->stack[top];
}

void RankedStorageStack::PushElement()
{
	if (this->length==STACKLENGTH)
	{
		cout << "ջ���ˣ�С��ƣ�" << endl;
		return;
	}

	int data = 0;
	cout << "���������ݣ��������֣���" << endl;
	cin >> data;
	this->top++;
	this->length++;
	this->stack[top] = data;
}

void RankedStorageStack::PopElement()
{
	if (this->top == -1)
	{
		cout << "��ջ��С��ƣ�" << endl;
		return;
	}

	this->length--;
	this->top--;
}

void RankedStorageStack::Traverse()
{
	if (this->top==-1)
	{
		cout << "ջ�����ˣ�������ë����" << endl;
		return;
	}

	int counter = this->length;
	while (this->top!=-1)
	{
		cout << "��" << counter << "������Ϊ��" << this->stack[top] << endl;
		this->top--;
		counter--;
	}
	this->length = 0;
}