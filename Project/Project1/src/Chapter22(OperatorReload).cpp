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

/*114、重载左移运算符
重载左移运算符（<<）用于输出自定义对象的成员变量，在实际开发中很有价值（调试和日志）。
只能使用非成员函数版本。
如果要输出对象的私有成员，可以配合友元一起使用。

补充：cout 是什么东西？

cout 是一个全局对象， 他的类型是std::ostream


*/

#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

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

int main()
{
    test146_main();
}
