#include <iostream>

using namespace std;

void testSizeOfType(){
    int numInt = 10;
    long numLong = 10;
    float numfloat = 10;
    double numdouble = 10;

    cout<<sizeof(numInt)<<endl;
    cout<<sizeof(numLong)<<endl;
    cout<<sizeof(numfloat)<<endl;
    cout<<sizeof(numdouble)<<endl;
}

void convertType(){
    bool b = 65;
    char a = b;
    int i = a;
    cout<<a<<endl;
    cout<<i<<endl;
}

void unsignedTest(){
    unsigned int unsignA = 1;
    int a = -1;
    cout << a + unsignA <<endl;
}

void scaleTest(){
    int hex = 0x123;
    cout << hex << endl;
    int oct = 0123;
    cout << oct << endl;
}

void useRef(){
    int b = 10,&a = b;
    double c = 20,&d = c;
}

void usePointer(){
    int a = 10;
    int *p = &a;
    *p = 20;
    cout<<p<<endl;
    cout<<a<<endl;

    int *p1 = nullptr;
    int *p2 = NULL;
    cout<<p1<<endl;
    cout<<p2<<endl;
}

void useVoidPoniter(){
    int a = 10;
    void *emptyP = nullptr;
    int *pInt = &a;
    emptyP = pInt;
    int *pInt2 = (int *)emptyP;
    cout<<*pInt2<<endl;
}

int main(){
    int *a;
    int *p,q;
    q = 10;
    cout<<q<<endl;
    cout<<p<<endl;
    cout<<a<<endl;
    system("pause");
    return 0;
}


/*
字面值常量
123(十进制),0123(八进制),0X123(十六进制)

引用：右值引用
    相当于为对象取的另外一个名字，引用即别名，其本身的值也会改变。
    1.引用（reference）为对象起了另外一个名字，
    2.引用类型引用（refers to）另外一种类型。
    3.通过将声明符写成&d的形式来定义引用类型，其中d是声明的变量名：
    4.引用本身不是一个对象，所以不能定义引用的引用
    tips:引用必须初始化，且无法令引用重新绑定到另外一个对象。

指针：
    指针的值应该是下列4种情况中的一个：
    1.指向一个对象。
    2.指向紧邻对象所占空间的下一个位置。
    3.空指针，意味着指针没有指向任何对象。
    4.无效指针，也就是上述情况之外的其他值。
    5.新标准下，最好使用nullptr，同时避免使用NULL。
    (虽然用NULL初始化指针和用0初始化指针是一样的，但最好使用nullptr，同时避免使用NULL)
    (把int变量直接赋给指针是错误的操作，即使int变量的值恰好为0也不行)
    6.建议初始化所有指针(这是造成运行时错误的一大原因)
        (1)使用未经初始化的地址详单与取访问一个本不存在的位置上本不存在的对象，（会随机给值，万一这个地址有东西就麻烦了）
        (2)并且，如果此时指针指向的地址是有内容的，那么我们就很难分清它到底是合法还是非法的了
        (3)因此建议初始化所有指针，并在定义了对象之后再定义指向它的指针

void *指针(这个是属于C语言中的内容)：
    可用于存在任意对象的地址。

一种观点会误以为，在定义语句中，类型修饰符（＊或&）作用于本次定义的全部变量，
比如说int* p,q，我们可能认为p,q的类型是int*，实际上基本数据类型是int而不是int *，*仅仅是修饰了p而已，
对该声明语句的其他变量，并不起作用


Tips:段错误（Segmentation fault）
    就是访问了不能访问的内存(比如说数组越界，访问0x0这个地址)
    给指针赋nullptr,NULL,就相当于给指针赋值为0,这个地方是不能随便访问的

*/