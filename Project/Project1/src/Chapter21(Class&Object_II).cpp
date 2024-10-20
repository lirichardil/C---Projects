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

在使用拷贝构造，如果不小心的话ua就会产生浅拷贝的bug
演示：
*/

class CBoy
{
public:
    string m_name;
    int m_age;
    // 没有参数的普通构造函数
    CBoy()
    {
        m_name.clear();
        m_age = 0;
        cout << "调用了CBoy()构造函数。\n";
    }

    // 没有重载的拷贝构造函数（默认拷贝构造函数）
    CBoy(const CBoy &b)
    {
        m_age = b.m_age;
        m_name = b.m_name;
        cout << "调用了CBoy(const Cboy&)。\n"
             << endl;
    }

    // 析构函数
    ~CBoy()
    {
        cout << "调用了~CBoy()\n";
    }

}

int
test139_main()
{
}
main()
{
}