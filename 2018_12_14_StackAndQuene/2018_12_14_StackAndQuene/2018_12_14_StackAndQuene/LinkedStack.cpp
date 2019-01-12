#include "restrainedList.h"
LinkedStack::LinkedStack()
{
	//链栈没有头结点
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
	cout << "请输入要生成的节点数目：" << endl;
	cin >> nodeNum;

	if (nodeNum<=0)
	{
		cout << "输入的生成的节点数目不能小于或等于0。" << endl;
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
		cout << "表达式不对头啊小老弟！" << endl;
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
		cout << "选择序号指定操作：" << endl;
		cout << "1.添加元素到栈中" << endl;
		cout << "2.删除元素" << endl;
		cout << "3.获取栈顶数据" << endl;
		cout << "4.遍历栈" << endl;
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
			cout << "栈顶数据为：" << GetElement()->data << endl;
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

void LinkedStack::PopElement()
{
	if (this->front==NULL)
	{
		cout << "小老弟不好意思，是空栈！" << endl;
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
	cout << "请输入数据（整型），小老弟：" << endl;
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
		cout << "小伙汁，栈空了！" << endl;
		return;
	}

	int counter = 1;
	while (this->front!=NULL)
	{
		cout << "第" <<counter <<"个数据为" << this->front->data<< endl;
		this->front = this->front->next;
	}
	this->front = top;
}

Node* LinkedStack::GetElement()
{
	if (this->front==NULL)
	{
		cout << "栈是空的，兄嘚！" << endl;
		return NULL;
	}
	
	return this->front;
}