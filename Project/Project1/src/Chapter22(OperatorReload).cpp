#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*146. 运算符重载基础 - 让操作更方便，更美观

运算符重载把并不是什么新鲜的事情。
C语言当中 将 * 重载成解引用和乘法


C++将运算符重载扩展到自定义的数据类型(类），它可以让对象操作更美观。

例如字符串string用加号（+）拼接、cout用两个左尖括号（<<）输出。

【使用语法】
运算符重载函数的语法：
    返回值 operator运算符(参数列表);
    可以看出这个语法和声明函数是一样的，但是对函数名有要求。

- 关于返回值
运算符重载函数的返回值类型要与运算符本身的含义一致。
如果涉及到连续调用， 比如要 score = g - 1-3-2,
那则需要返回它本身

-关于参数列表

非成员函数版本的重载运算符函数：形参个数与运算符的操作数个数相同；
成员函数版本的重载运算符函数：形参个数比运算符的操作数个数少一个，其中的一个操作数隐式传递了调用对象。
如果同时重载了非成员函数和成员函数版本，会出现二义性。


注意：
1）返回自定义数据类型的引用可以让多个运算符表达式串联起来。（不要返回局部变量的引用）
2）重载函数参数列表中的顺序决定了操作数的位置。
3）重载函数的参数列表中至少有一个是用户自定义的类型，防止程序员为内置数据类型重载运算符。
4）如果运算符重载既可以是成员函数也可以是全局函数，应该优先考虑成员函数，这样更符合运算符重载的初衷。
5）重载函数不能违背运算符原来的含义和优先级。
6）不能创建新的运算符。
7）以下运算符不可重载：

sizeof             sizeof运算符
.                  成员运算符
.*                 成员指针运算符
::                 作用域解析运算符
?:                 条件运算符
typeid            一个RTTI运算符
const_cast        强制类型转换运算符
dynamic_cast     强制类型转换运算符
reinterpret_cast   强制类型转换运算符
static_cast        强制类型转换运算符

8）以下运算符只能通过成员函数进行重载：
=                赋值运算符
()                函数调用运算符
[]                下标运算符
->               通过指针访问类成员的运算符

*/

// 业务需求： 添加两个成员的分数
class CGirl
{
    friend int operator+(CGirl &g, int score);
    // friend CGirl &operator-(CGirl &g, int score);

private:
    int m_age;
    int m_score;

public:
    string m_name;

    // 默认构造
    CGirl()
    {
        m_age = 11;
        m_score = 20;
    }
    void show()
    {
        cout << "m_age = " << m_age << " m_score = " << m_score << endl;
    }
    CGirl &operator-(int score)
    {
        m_score = m_score - score; // m_score 是私有成员，需要添加到friend
        return *this;
    }
};

// 写一个重载函数

int operator+(CGirl &g, int score) // 更合理的返回值应该是 int 类型
{
    g.m_score = g.m_score + score; // m_score 是私有成员，需要添加到friend
}

// CGirl &operator-(CGirl &g, int score)
// {
//     g.m_score = g.m_score - score; // m_score 是私有成员，需要添加到friend
//     return g;
// }

void test146_main()
{
    CGirl g;
    // g = g + 30; 没有实现重载是这个肯定是不行的
    // 添加了 opertor+函数后，底层还是调用函数，只是c++编译器将
    // 两个形参解释成了放在运算符的两边
    g.show();
    int score = g + 50;
    // int score = g+40+20; 报错。

    g = g - 30 - 23 - 32; // 本质是函数的多次调用
    // 等同于
    //  g = operator-(g,20)),5),3)
    // g = 30-g-23 会报错，见【注意】的第二点 如果需要实现这样的操作，
    // 则需要再写一个重载函数，把位置调换一下

    g.show();
}

/*147 关系运算符重载
重载关系运算符（==、!=、>、>=、<、<=）用于比较两个自定义数据类型的大小。
可以使用非成员函数和成员函数两种版本，建议采用成员函数版本。

*/

class CGirl2 // 超女类CGirl。
{
    string m_name; // 姓名。
    int m_yz;      // 颜值：1-千年美人；2-百年美人；3-绝代美人；4-极漂亮；5-漂亮；6-一般；7-歪瓜裂枣。
    int m_sc;      // 身材：1-火辣；2-...；3-...；4-...；5-...；6-...；7-膘肥体壮。
    int m_acting;  // 演技：1-完美；2-...；3-...；4-...；5-...；6-...；7-四不像。
public:
    // 四个参数的构造函数。
    CGirl2(string name, int yz, int sc, int acting)
    {
        m_name = name;
        m_yz = yz;
        m_sc = sc;
        m_acting = acting;
    }
    // 比较两个超女的商业价值。
    bool operator==(const CGirl2 &g1) // 相等==
    {
        if ((m_yz + m_sc + m_acting) == (g1.m_yz + g1.m_sc + g1.m_acting))
            return true;
        return false;
    }
    bool operator>(const CGirl2 &g1) // 大于>
    {
        if ((m_yz + m_sc + m_acting) < (g1.m_yz + g1.m_sc + g1.m_acting))
            return true;
        return false;
    }
    bool operator<(const CGirl2 &g1) // 小于<
    {
        if ((m_yz + m_sc + m_acting) > (g1.m_yz + g1.m_sc + g1.m_acting))
            return true;
        return false;
    }
};

void test147_main()
{
    CGirl2 g1("西施", 1, 2, 2), g2("冰冰", 1, 1, 1);

    if (g1 == g2)
        cout << "西施和冰冰的商业价值相同。\n";
    else if (g1 > g2)
        cout << "西施商业价值相同比冰冰大。\n";
    else
        cout << "冰冰商业价值相同比西施大。\n";
}

/*148、重载左移运算符
重载左移运算符（<<）用于输出自定义对象的成员变量，在实际开发中很有价值（调试和日志）。
只能使用非成员函数版本。
如果要输出对象的私有成员，可以配合友元一起使用。

补充：cout 是什么东西？

cout 是一个全局对象， 他的类型是std::ostream


*/

class CGirl3 // 超女类CGirl。
{
    friend ostream &operator<<(ostream &cout, const CGirl3 &g);
    string m_name; // 姓名。
    int m_xw;      // 胸围。
    int m_score;   // 评分。
public:
    // 默认构造函数。
    CGirl3()
    {
        m_name = "西施";
        m_xw = 87;
        m_score = 30;
    }

    // 自我介绍的方法。
    void show()
    {
        cout << "姓名：" << m_name << "，胸围：" << m_xw << "，评分：" << m_score << endl;
        // 第一次调用时 相当于 调用了两个实参是cout 和 "姓名" 的函数，返回值是cout的对象
    }
};

ostream &operator<<(ostream &cout, const CGirl3 &g)
{
    cout << "姓名：" << g.m_name << "，胸围：" << g.m_xw << "，评分：" << g.m_score;
    return cout;
}

/*149、 重载下标
如果对象中有数组，重载下标运算符[]，操作对象中的数组将像操作普通数组一样方便。
下标运算符必须以成员函数的形式进行重载。
下标运算符重载函数的语法：
    返回值类型 &perator[](参数);
或者：
    const 返回值类型 &operator[](参数) const;
使用第一种声明方式，[]不仅可以访问数组元素，还可以修改数组元素。
使用第二种声明方式，[]只能访问而不能修改数组元素。
在实际开发中，我们应该同时提供以上两种形式，这样做是为了适应const对象，因为通过const 对象只能调用const成员函数，如果不提供第二种形式，那么将无法访问const对象的任何数组元素。
在重载函数中，可以对下标做合法性检查，防止数组越界。



*/

class CGirl4
{
private:
    string m_boys[3];

public:
    int number;
    string m_name;
    // 默认构造函数
    CGirl4()
    {
        m_boys[0] = "Richard";
        m_boys[1] = "David";
        m_boys[2] = "Tom";
    }
    // 显示全部男朋友的姓名。

    void show()
    {
        cout << m_boys[0] << "、" << m_boys[1] << "、" << m_boys[2] << endl;
        cout << "m_number = " << number << endl;
    }

    string &operator[](int ii) // 注意： 这里函数的返回值是引用，
    // 引用的本质是指针常量，也就是 string* const ptr = &m_boys[ii]
    // 是一个指针，指向m_boys的地址，指针本身是一个 常量，不能指向别的地址。
    // 指针的内容（指针指向的变量）是可以修改的
    {
        return m_boys[ii];
    }

    // 重载 operator[]函数， 为的是适配常对象
    const string &operator[](int ii) const
    {
        return m_boys[ii];
    }
    // 可以添加判断数组越界的处理
};

void test149_main()
{
    string a = "abcd"; // string a 创建了一个 类是string的对象a
    cout << " a = " << a << endl;
    cout << "a[0] = " << a[0] << endl; // 重载了【】
    CGirl4 g;
    g.show();
    g[1] = "Kevin";
    g.show();

    const CGirl4 g1; // 创建常对象，如果没有const string& operator[](int ii) const,则无法调用
    // g1[2] = "Richard"; //会报错,常对象不能修改
    cout << "g1[1] = " << g1[1] << endl; // 只能访问常函数
}

/*150、 重载赋值运算符
C++编译器可能会给类添加四个函数：
- 默认构造函数，空实现。
- 默认析构函数，空实现。
- 默认拷贝构造函数，对成员变量进行浅拷贝。
- 默认赋值函数, 对成员变量进行浅拷贝。

对象的赋值运算是用一个已经存在的对象，给另一个已经存在的对象赋值。
如果类的定义中没有重载赋值函数，编译器就会提供一个默认赋值函数。
如果类中重载了赋值函数，编译器将不提供默认赋值函数。
重载赋值函数的语法：类名 & operator=(const 类名 & 源对象);
注意：
	编译器提供的默认赋值函数，是浅拷贝。
	如果对象中不存在堆区内存空间，默认赋值函数可以满足需求，否则需要深拷贝。
	赋值运算和拷贝构造不同：拷贝构造是指原来的对象不存在，用已存在的对象进行构造；赋值运算是指已经存在了两个对象，把其中一个对象的成员变量的值赋给另一个对象的成员变量。


*/
class CGirl5 // 超女类CGirl。
{
public:
    int m_bh;      // 编号。
    string m_name; // 姓名。
    int *m_ptr;    // 计划使用堆区内存。

    CGirl5() { m_ptr = nullptr; }
    ~CGirl5()
    {
        if (m_ptr)
            delete m_ptr;
    }
    // 显示全部成员变量。
    void show() { cout << "编号：" << m_bh << "，姓名：" << m_name << "，m_ptr=" << m_ptr << /* "，*m_ptr=" << *m_ptr<< */ endl; }

    CGirl5 &operator=(const CGirl5 &g) // 返回引用，目的是节省内存且可以修改
    {

        // 不涉及指针的重载
        m_bh = g.m_bh;
        m_name = g.m_name;
        if (this == &g)
            return *this; // 如果是自己给自己赋值。g1 = g1

        // 重新写深拷贝
        if (g.m_ptr == nullptr) // 如果源对象的指针为空，则清空目标对象的内存和指针。也就是将空指针赋值
        {
            if (m_ptr != nullptr)
            {
                delete m_ptr;
                m_ptr = nullptr;
            }
        }
        else // 如果源对象的指针不为空。
        {
            // 如果目标对象的指针为空，先分配内存。
            if (m_ptr == nullptr)
                m_ptr = new int;
            // 然后，把源对象内存中的数据复制到目标对象的内存中。
            memcpy(m_ptr, g.m_ptr, sizeof(int));
        }

        m_bh = g.m_bh;
        m_name = g.m_name;
        cout << "调用了重载赋值函数。\n"
             << endl;
        return *this;
    }
};

void test150_main()
{
    CGirl5 g1,g2;
    g1.m_bh = 8; g1.m_name = "g1"; g1.m_ptr = new int(3);
    g1.show();
    g2.show();

    g2 = g1;
    g2.show();
    cout << "g2.m_ptr = " << *g2.m_ptr << endl;
}


/* 151 重载new&delete运算符
重载new和delete运算符的目是为了自定义内存分配的细节。（内存池：快速分配和归还，无碎片）
建议先学习C语言的内存管理函数malloc()和free()。
在C++中，使用new时，编译器做了两件事情：
    1）调用标准库函数operator new()分配内存；
    2）调用构造函数初始化内存；

使用delete时，也做了两件事情：
    1）调用析构函数；
    2）调用标准库函数operator delete()释放内存。
构造函数和析构函数由编译器调用，我们无法控制。


但是，可以重载内存分配函数operator new()和释放函数operator delete()。
1）重载内存分配函数的语法：void* operator new(size_t size);   
参数必须是size_t，返回值必须是void*。
2）重载内存释放函数的语法：void operator delete(void* ptr)   
参数必须是void *（指向由operator new()分配的内存），返回值必须是void。
重载的new和delete可以是全局函数，也可以是类的成员函数。
为一个类重载new和delete时，尽管不必显式地使用static，但实际上仍在创建static成员函数。
编译器看到使用new创建自定义的类的对象时，它选择成员版本的operator new()而不是全局版本的new()。
new[]和delete[]也可以重载。

*/

void* operator new(size_t size) // 参数必须是size_t（unsigned long long），返回值必须是void*。
{

}

void operator delete(void* ptr)   // 参数必须是void *，返回值必须是void。


void test151_main()
{
    int*p1 = new int(3);
    cout << "(地址)p1 = " << (void *)p1 << ", *p1 = " << *p1 << endl;
    delete p1; 
}



int main()
{
    // test146_main();
    // test149_main();
    //test150_main();
    test151_main();
}
