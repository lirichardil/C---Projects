#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/* 84、函数的默认参数

默认参数是指调用函数的时候，如果不书写实参，那么将使用的一个缺省值。
语法：返回值 函数名(数据类型 参数=值, 数据类型 参数=值,……);
注意：
	如果函数的声明和定义是分开书写的，在函数声明中书写默认参数，函数的定义中不能书写默认参数。
	函数必须从右到左设置默认参数。也就是说，如果要为某个参数设置默认值，则必须为它后面所有的参数设置默认值。
	调用函数的时候，如果指定了某个参数的值，那么该参数前面所有的参数都必须指定。


*/
void test84_func1(const string &message = "f1默认参数") // string 是类，应该传入引用，避免拷贝。
// 且函数中不会修改name 的值，所以应该再增加const
{
    cout << "func1 is calling" << message << endl;
}

// 上面函数的声明和定义是写在一起的。一般开发中函数的声明和定义一般都是分开写的，这种
// 情况在函数声明中书写默认参数，函数的定义中不能书写默认参数。

void test84_func2(const string &message = "f2默认参数"); // 函数的声明

void test84_main()
{
    test84_func1(); // 缺省内容
    test84_func1("fun1传入实参");
    test84_func2();
}

void test84_func2(const string &message) // 定义中不能写默认参数
{
    cout << "func1 is calling" << message << endl;
}

/*85、函数重载(函数多态)

函数重载（函数多态）是指设计一系列同名函数，让它们完成相同（似）的工作。
C++允许定义名称相同的函数，条件是它们的特征（形参的个数、数据类型和排列顺序）不同。

C++允许定义名称相同的函数，条件是它们的特征（形参的个数、数据类型和排列顺序）不同。
#1	int func(short a  ,string b);
#2	int func(int a    ,string b);
#3	int func(double a,string b);
#4	int func(int a    ,string b, int len);
#5	int func(string b , int a);
调用重载函数的时候，在代码中我们用相同的函数名，但是，后面的实参不一样，编译器根据实参与重载函数的形参进行匹配，
然后决定调用具体的函数，如果匹配失败，编译器将视为错误。
在实际开发中，视需求重载各种数据类型，不要重载功能不同的函数。

注意：
- 使用重载函数时，如果数据类型不匹配，C++尝试使用类型转换与形参进行匹配，
如果转换后有多个函数能匹配上，编译将报错。
- 引用可以作为函数重载的条件，但是，调用重载函数的时候，如果实参是变量，编译器将形参类型的本身和类型引用视为同一特征。
- 如果重载函数有默认参数，调用函数时，可能导致匹配失败。
- const不能作为函数重载的特征。int func(string b , int a); 和int func(const string b , const int a); 是同一个函数，不会重载

- 返回值的数据类型不同不能作为函数重载的特征。
- 原理： C++的名称修饰：编译时，对每个函数名进行加密，替换成不同名的函数。
        void MyFunctionFoo(int,float);
        void MyFunctionFoo(long,float);
        ?MyFunctionFoo@@YAXH(int,float);
        #void MyFunctionFoo^$@(long,float);
*/

// Test85_func1解释： 引用可以作为函数重载的条件，但是，调用重载函数的时候，
// 如果实参是变量，编译器将形参类型的本身和类型引用视为同一特征。
void test85_func1(short bh, string messages)
{
    cout << " short 传入编号为： " << bh << "信息是" << messages << endl;
}

void test85_func1(short &bh, string messages)
{
    cout << " short& 传入编号为： " << bh << "信息是" << messages << endl;
}

void test85_MySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void test85_MySwap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void test85_main()
{
    int a = 3;
    int b = 5;
    cout << "before swap a = " << a << ", b = " << b << endl;
    test85_MySwap(a, b);
    cout << "after swap a = " << a << ", b = " << b << endl;

    string c = "hello";
    string d = "Richard";
    cout << "before swap c = " << c << ", d = " << d << endl;
    test85_MySwap(c, d);
    cout << "after swap c = " << c << ", d = " << d << endl;

    short bh = 10;
    // test85_func1(bh, "传入编号为10"); // 编译时会报错，因为有两个函数test85_func1都可以调用
    test85_func1(10, "传入编号为10"); // 编译可以通过，调用的是short 而不是short&， 因为常量不能引用
}

/* 86. 内联函数 - 作用： 提高程序运行速度
C++将内联函数的代码组合到程序中，可以提高程序运行的速度。
语法：在函数声明和定义前加上关键字inline。
通常的做法是将函数声明和定义写在一起。
注意：
- 内联函数节省时间，但消耗内存。
- 如果函数过大，编译器可能不将其作为内联函数。
- 内联函数不能递归。

*/

inline void test86_func1(const short bh, const string message); // 声明

void test86_main()
{
    // 连续调用三次test86_func1
    // 在调用这些函数是，操作系统会将这些指令加载到内存中
    // 每条指令都有他的内存地址，然后再逐步执行这些指令，如果调用这些函数，就跳转
    // 到函数的地址执行函数。
    // 跳转函数是有代价开销的，主要体现在三个方面
    // 1. 跳转钱保存原来指令的内存地址
    // 2. 把实参拷贝到堆栈
    // 3. 将返回值放在寄存器中返回

    // test86_func1(3, "第一次调用");

    // test86_func1(5, "第二次调用");

    // test86_func1(7, "第三次调用");

    // C++提供了另外一种选择，就是在函数声明和定义的时候添加inline 关键字
    // 在编译的时候，表白函数的代码将嵌入到程序中，做一个替换，而非调用（跳转
    // 上面的代码相当于：
    /*
    {
        short bh = 3;
        string message = " 第一次调用";
        cout << "func1传入编号为" << bh << " 内容是： " << messages << endl;
    }
    {
        short bh = 5;
        string message = " 第二次调用";
        cout << "func1传入编号为" << bh << " 内容是： " << messages << endl;
    }
    {
        short bh = 7;
        string message = " 第三次调用";
        cout << "func1传入编号为" << bh << " 内容是： " << messages << endl;
    }*/
}

inline void test86_func1(short bh, string message) // 定义
{
    cout << "func1传入编号为" << bh << " 内容是： " << message << endl;
}

int main()
{
    // test84_main();
    test85_main();
    return 0;
}