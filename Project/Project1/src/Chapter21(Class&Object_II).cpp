#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*139 深拷贝和浅拷贝

在学习深拷贝和浅拷贝前，我们先考虑一个案例：

假设有两个类A,B，分别维护了两个不同的指针, 他们指向同一片内存

对象A   对象B
m_ptr   m_prt
  \       /
    0x00B3F

这样会产生两个问题
1. 如果改变对象A中m_ptr 地址中的内容，对象B指针看到的也会被改变。
2. 一般我们会将释放内存的代码放在析构函数中， 当其中一个被析构了，另外一个就变成了野指针
(因为他指向的地址已经被释放了)

在使用拷贝构造，如果不小心的话就会产生浅拷贝的bug
演示：
*/

class CBoy
{
public:
    string m_name;
    int m_age;
    // 没有参数的普通构造函数

    int *m_ptr;
    CBoy()
    {
        // 在普通构造中将指针设置为空
        m_ptr = nullptr;
        m_name.clear();
        m_age = 0;
        cout << "调用了CBoy()构造函数。\n";
    }

    // 没有重载的拷贝构造函数（默认拷贝构造函数）
    // CBoy(const CBoy &b)
    // {
    //     m_age = b.m_age;
    //     m_name = b.m_name;
    //     cout << "调用了CBoy(const Cboy&)。\n"
    //          << endl;
    // }

    // 析构函数
    ~CBoy()
    {
        if (m_ptr == nullptr)
        {
            delete m_ptr;
            m_ptr = nullptr;
        }
        cout << "调用了~CBoy()\n";
    }
    // 下面我们自己写深拷贝：
    // 第一步，分配内存
    // 第二步，拷贝数据
    CBoy(const CBoy &bb)
    {
        m_name = bb.m_name;
        m_age = bb.m_age;

        m_ptr = new int; // 分配内存
        //*m_ptr = *bb.m_ptr;
        memcpy(m_ptr, bb.m_ptr, sizeof(int)); // 拷贝数据
        cout << "调用了 深度拷贝构造" << endl;
    }
};

void test139_main()
{
    CBoy b1;
    b1.m_name = "Boy1";
    b1.m_ptr = new int(3); // 将b1 的m_ptr指针赋值

    CBoy b2(b1); // 程序运行到这里就会报错了。
    // 因为在拷贝构造时，这里用的时浅拷贝，指针（地址）被简单的拷贝过去了，
    // 相当于有两个指针指向同一片区域
}

// 140、初始化列表(重新学习)
/*
构造函数的执行可以分成两个阶段：初始化阶段和计算阶段（初始化阶段先于计算阶段）。

- 初始化阶段：全部的成员都会在初始化阶段初始化。
- 计算阶段：一般是指用于执行构造函数体内的赋值操作。

构造函数除了参数列表和函数体之外，还可以有初始化列表。


初始化列表的语法：
类名(形参列表):成员一(值一), 成员二(值二),..., 成员n(值n)
{......}


注意：
1）如果成员已经在初始化列表中，则不应该在构造函数中再次赋值。
2）初始化列表的括号中可以是具体的值，也可以是构造函数的形参名，还可以是表达式。（非常重要）



3）初始化列表与赋值有本质的区别，如果成员是类，使用初始化列表调用的是成员类的拷贝构造函数，
//而赋值则是先创建成员类的对象（将调用成员类的普通构造函数），然后再赋值。



4）如果成员是类，初始化列表对性能略有提升。
5）如果成员是常量和引用，必须使用初始列表，因为常量和引用只能在定义的时候初始化。
6）如果成员是没有默认构造函数的类，则必须使用初始化列表。
7）拷贝构造函数也可以有初始化列表。
8）类的成员变量可以不出现在初始化列表中。
9）构造函数的形参先于成员变量初始化。

*/
//[注意3] 初始化列表和赋值有着根本的区别。如果赋值的成员是类，使用初始化列表调用的是成员类的
// 拷贝构造函数，而赋值则是先创建成员类的对象（将调用成员类的普通构造函数），然后再赋值。

class CGirl
{
public:
    string m_name;
    CGirl() // 没有参数的普通构造函数，默认构造函数。
    {
        m_name.clear();
        cout << "调用CGirl()构造函数" << endl;
    }
    CGirl(string name)
    {
        m_name = name;
        cout << "调用了    CGirl(string name) 构造函数。 \n";
    }
    CGirl(const CGirl &gg) // 默认拷贝构造函数
    {
        m_name = gg.m_name;
        cout << "调用了CGirl(ocnst CGirl(const CGirl&gg)) 拷贝构造函数 \n";
    }
};

class CBoy1
{
public:
    string m_name;
    int m_age;
    CGirl m_girl;

    // CBoy1() : m_name("Boy1"), m_age(23) // 初始化列表可以是具体的值，也可以是形参名

    // {
    //     cout << "调用了CBoy 普通构造函数" << endl;
    //     // m_name = "Boy2"; //[注意1]如果在构造函数里面再次赋值，就会覆盖掉初始化列表的值
    //     // m_age = 12;
    // }

    //[注意2] 初始化列表可以是形参名，还可以是表达式
    CBoy1(string name, int age) : m_name("美丽的" + name), m_age(age) // 两个参数的构造函数
    {

        cout << "调用了 CBoy1(string name, int age) 构造函数" << endl;
    }

    //[注意3]
    CBoy1(string name, int age, CGirl girl) : m_name(name), m_age(age)
    {
        // 用赋值的方法给CGril赋值
        m_girl.m_name = girl.m_name;
    }

    void show()
    {
        cout << "Name = " << this->m_name << "age = " << this->m_age << m_girl.m_name << endl;
    }
};

void test140_main()
{
    // CBoy1 boy1; // 构造时候调用了没有参数的普通构造函数
    // CBoy1 boy1("LILI", 19);
    CGirl girl("Angie");
    CBoy1 boy1("Li", 11, girl); //[注意3] 使用初始化列表时，先初始化构造函数的形参对象，然后再初始化类的成员

    boy1.show();
}

/*
//141. const修饰成员函数
在类的成员函数后面加const关键字，表示在成员函数中保证不会修改调用对象的成员变量。

注意：
1）mutable可以突破const的限制，被mutable修饰的成员变量，将永远处于可变的状态，
在const修饰的函数中，mutable成员也可以被修改。
2）非const成员函数可以调用const成员函数和非const成员函数。
3）const成员函数不能调用非const成员函数。


4）非const对象可以调用const修饰的成员函数和非const修饰的成员函数。
5）const对象只能调用const修饰的成员函数，不能调用非cosnt修饰的成员函数。



这里出现了令人纠结的三个问题：
1、为什么要保护类的成员变量不被修改？
2、为什么用const保护了成员变量，还要再定义一个mutable关键字来突破const的封锁线？
3、到底有没有必要使用const和mutable这两个关键字？
保护类的成员变量不在成员函数中被修改，是为了保证模型的逻辑正确，
通过用const关键字来避免在函数中错误的修改了类对象的状态。
并且在所有使用该成员函数的地方都可以更准确的预测到使用该成员函数的带来的影响。
而mutable则是为了能突破const的封锁线，
让类的一些次要的或者是辅助性的成员变量随时可以被更改。
没有使用const和mutable关键字当然没有错，const和mutable 关
键字只是给了建模工具更多的设计约束和设计灵活性，而且程序员也可以把更多的
逻辑检查问题交给编译器和建模工具去做，从而减轻程序员的负担。


*/
class CBoy2
{
public:
    mutable string m_name;
    int m_age;
    // 两个参数的普通构造函数
    CBoy2(const string &name, int age)
    {
        m_name = name;
        m_age = age;
        cout << "调用了CBoy2(const string &name, int age)" << endl;
    }
};

int main()
{
    test140_main();
}