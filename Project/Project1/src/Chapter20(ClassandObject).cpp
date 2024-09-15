#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 面向对象编程
// 1. 抽象
// 2. 多态
// 3. 代码复用
// 4. 封装与数据隐藏
// 5， 代码重用

/*101、从结构体到类
对面向对象编程来说，一切都是对象，对象用类来描述。
类把对象的数据和操作数据的方法作为一个整体考虑。
定义类的语法：

class 类名
{
public:
成员一的数据类型  成员名一;
成员二的数据类型  成员名二;
成员三的数据类型  成员名三;
......
成员n的数据类型  成员名n;
};

注意：
- 类的成员可以是变量，也可以是函数。
- 类的成员变量也叫属性。
- 类的成员函数也叫方法/行为，类的成员函数可以定义在类的外面。
- 用类定义一个类的变量叫创建（或实例化）一个对象。
- 对象的成员变量和成员函数的作用域和生命周期与对象的作用域和生命周期相同。

*/

struct st_girl
{
    string name;
    int age;
    int height;
    double weight;
}

void
test101_main()
{
}

int main()
{
}