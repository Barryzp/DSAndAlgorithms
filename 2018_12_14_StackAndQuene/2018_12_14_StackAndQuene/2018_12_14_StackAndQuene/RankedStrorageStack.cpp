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
	cout << "请输入初始化的栈元素个数：" << endl;
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
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到栈中" << endl;
		cout << "2.删除元素" << endl;
		cout << "3.获取栈顶数据" << endl;
		cout << "4.清空数据并遍历栈" << endl;
		cout << "5.查看长度" << endl;
		cout << "6.退出" << endl;
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
			cout<<"栈顶数据为："<<GetElement()<<endl;
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

int RankedStorageStack::GetElement()
{
	if (this->top==-1)
	{
		cout << "空栈，小伙计！" << endl;
		return -999;
	}

	return this->stack[top];
}

void RankedStorageStack::PushElement()
{
	if (this->length==STACKLENGTH)
	{
		cout << "栈满了，小伙计！" << endl;
		return;
	}

	int data = 0;
	cout << "请输入数据（整型数字）：" << endl;
	cin >> data;
	this->top++;
	this->length++;
	this->stack[top] = data;
}

void RankedStorageStack::PopElement()
{
	if (this->top == -1)
	{
		cout << "空栈，小伙计！" << endl;
		return;
	}

	this->length--;
	this->top--;
}

void RankedStorageStack::Traverse()
{
	if (this->top==-1)
	{
		cout << "栈都空了，遍历鸡毛啊！" << endl;
		return;
	}

	int counter = this->length;
	while (this->top!=-1)
	{
		cout << "第" << counter << "个数据为：" << this->stack[top] << endl;
		this->top--;
		counter--;
	}
	this->length = 0;
}