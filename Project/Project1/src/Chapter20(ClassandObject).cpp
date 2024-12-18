#include <iostream>
#include <cstring>

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
(当这个类被销毁时，类里面的成员将不存在。)
*/

class CGirl
{
private:
    string m_secret;

public:
    string m_name;
    int m_age;
    int sex;
    enum
    {
        girl = 1,
        boy = 2
    }; // 类中使用枚举也是可以的
    void setter(string name, int age, string secret); // 类中只需要声明
    /*void setter(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    */
    void getter()
    {
        cout << "Name is " << m_name << ", Age is" << m_age << "secret is " << m_secret
             << endl;
    }
};

// 也可以把类的方法定义在类的外面：
void CGirl::setter(string name, int age, string secret)
{
    m_secret = secret;
    m_name = name;
    m_age = age;
}

void test101_main()
{
    CGirl girl;
    girl.setter("Angie", 12, "Girl");
    girl.getter();
}

/*102、类的访问权限
类的成员有三种访问权限：public、private和protected，分别表示公有的、私有的和受保护的。

在类的内部（类的成员函数中），无论成员被声明为 public还是private，都可以访问。
在类的外部（定义类的代码之外），只能访问public成员，不能访问 private、protected成员。

在一个类体的定义中，private 和 public 可以出现多次。

结构体的成员缺省为public，类的成员缺省为private。

private的意义在于隐藏类的数据和实现，把需要向外暴露的成员声明为public。


*/

void test102_main()
{
    CGirl girl;
    girl.setter("Angie", 12, "Girl");
    // cout << girl.m_secret << endl;会报错
    girl.getter();
}

/*103 简单使用类
编程思想和方法的改变，披着C++外衣的C程序员。
1）类的成员函数可以直接访问该类其它的成员函数（可以递归）。
在类的成员函数中做递归更方便，不需要传入额外参数，可以借助类的成员来记录递归内容。
2）类的成员函数可以重载，可以使用默认参数。
3）类指针的用法与结构体指针用法相同。
4）类的成员可以是任意数据类型（类中枚举）。
5）可以为类的成员指定缺省值（C++11标准）。
6）类可以创建对象数组，就像结构体数组一样。
7）对象可以作为实参传递给函数，一般传引用。
8）可以用new动态创建对象，用delete释放对象。
9）在类的外部，一般不直接访问（读和写）对象的成员，而是用成员函数。数据隐藏是面向对象编程的思想之一。
10）对象一般不用memset()清空成员变量，可以写一个专用于清空成员变量的成员函数。
11）对类和对象用sizeof运算意义不大，一般不用。
12）用结构体描述纯粹的数据，用类描述对象。
13）在类的声明中定义的函数都将自动成为内联函数；在类的声明之外定义的函数如果使用了inline限定符，也是内联函数。
14）为了区分类的成员变量和成员函数的形参，把成员变量名加m_前缀或_后缀，如m_name或name_。
15）类的分文件编写。




*/

void demo1() // 第4点，在类中使用枚举
{
    CGirl girl;
    girl.sex = girl.boy;
}

// 第13点： 13）在类的声明中定义的函数都将自动成为内联函数；
// 在类的声明之外定义的函数如果使用了inline限定符，也是内联函数。

// 复习： 内联函数定义： 内联函数是一种编程语言结构，通常与类一起使用。如果一个函数被声明为内联的，那么在编译时，编译器会将该函数的代码副本放置在每个调用该函数的地方。这意味着，
// 不再需要函数调用的开销，因为函数体直接插入到调用处1。

/*104、构造函数和析构函数
构造函数：在创建对象时，自动的进行初始化工作。
析构函数：在销毁对象前，自动的完成清理工作。

1）构造函数
    语法：类名(){......}
    -	访问权限必须是public。
    -	函数名必须与类名相同。
    -	没有返回值，不写void。
    -	可以有参数，可以重载，可以有默认参数。
    -	创建对象时只会自动调用一次，不能手工调用。
2）析构函数
语法：~类名(){......}
    - 访问权限必须是public。
    - 函数名必须在类名前加~。
    - 没有返回值，也不写void。
    - 没有参数，不能重载。
    - 销毁对象前只会自动调用一次，但是可以手工调用。

*/

class CBoy
{
public:
    string m_name;
    int m_age;
    char m_memo[301]; // C风格备注
    void setter(string name, int age)
    {
        m_age = age;
        m_name = name;
    }
    void getter()
    {
        cout << "name is" << m_name << "age is" << m_age << endl;
    }
    // 构造函数：没有范围值，必须是公有，自动调用
    CBoy() // 对成员初始化
    {
        m_name.clear();
        m_age = 0;
        memset(m_memo, 0, sizeof(m_memo));
        cout << "构造函数调用结束" << endl; // 方便调试
    }
    // 构造函数可以重载，可以带参数
    CBoy(string name)
    {
        m_name.clear();
        m_age = 0;
        memset(m_memo, 0, sizeof(m_memo));
        m_name = name;
        cout << "m_name is" << m_name << endl;
        cout << "构造函数调用结束" << endl; // 方便调试
    }

    // 析构函数，没有返回值，没有参数，不能重载， 但是可以手工调用
    ~CBoy() // 用于释放资源，delete 等
    {
        cout << "调用了析构函数" << endl;
    }
    // 声明拷贝构造，105课会用到
    CBoy(const CBoy &b);
    // 声明拷贝构造函数的重载，105课用到
    CBoy(const CBoy &b, int ii);
};

/*
注意：
1）	如果没有提供构造/析构函数，编译器将提供空实现的构造/析构函数。
2）	如果提供了构造/析构函数，编译器将不提供空实现的构造/析构函数。
3）	创建对象的时候，如果重载了构造函数，编译器根据实参匹配相应的构造函数。没有参数的构造函数也叫默认构造函数。
4）	创建对象的时候不要在对象名后面加空的圆括号，编译器误认为是声明函数。
（如果没有构造函数、构造函数没有参数、构造函数的参数都有默认参数）

    CBoy boy(); 这个是个坑，这行代码的意思是返回一个类型是CBoy的函数，不是创建对象；


5）	在构造函数名后面加括号和参数不是调用构造函数，是创建匿名对象。
    CBoy(); //这句话并不是调用构造函数，因为构造函数不可以被调用，
    //这句话的意思是创建一个匿名对象 ， 相当于 CBoy x();只是 x是匿名的

6）	接受一个参数的构造函数允许使用赋值语法将对象初始化为一个值（可能会导致问题，不推荐）。
    假设你的构造函数如下
    CBoy(int age){...}
    那可以直接用 = 赋值
    CBoy boy =10;

7）	以下两行代码有本质的区别：
    下面这行只会调用一次构造函数一次析构函数
    CGirl girl = CGirl("西施"20);  // 显式创建对象。

    下面两行代码， 先创建一个对象girl， 调用一次构造，一次析构
    然后再创建一个匿名对象，赋值（西施，20),这是又会调用一次构造，一次析构
    CGirl girl;                   // 创建对象。
    girl = CGirl("西施"20);        // 创建匿名对象，然后给现有的对象赋值。


8）	用new/delete创建/销毁对象时，也会调用构造/析构函数。
*/

void test104_bullet8()
{
    CBoy *boy = new CBoy;
    boy->getter();
    delete boy;
}

/*
9）	不建议在构造/析构函数中写太多的代码，可以调用成员函数。
10）除了初始化，不建议让构造函数做太多工作（只能成功不会失败）。
11）C++11支持使用统一初始化列表。
    CGirl girl = {"西施"20};
    CGirl girl  {"西施"20};
    CGirl* girl = new CGirl{ "西施"20 };
12）如果类的成员也是类，创建对象的时候，先构造成员类；销毁对象的时候，先析构自身，再析构成员类（视频中有误）。
*/

void test104_main()
{
    CBoy boy; // 没有参数名，调用没有参数的构造函数
    boy.getter();
    CBoy boy2("richard");
    boy2.~CBoy(); // 可以手工调用，但是应用场景不多

    /*这里注意一下输出的顺序：
    构造函数调用结束
    调用了析构函数
    调用了析构函数
    调用了析构函数
    */

    test104_bullet8();
}

/*105 拷贝构造函数
用一个已存在的对象创建新的对象，不会调用（普通）构造函数，而是调用拷贝构造函数。
如果类中没有定义拷贝构造函数，编译器将提供一个拷贝构造函数，它的功能是把已存在对象的成员变量赋值给新对象的成员变量。


用一个已存在的对象创建新的对象语法：
    类名 新对象名(已存在的对象名);
    CBoy oldboy;
    CBoy newboy(oldboy);

    类名 新对象名=已存在的对象名;
    CBoy newboy = oldboy;


拷贝构造函数的语法：
类名(const 类名& 对象名){......}

用户没有写拷贝构造时，编译器自动给出
*/

/*
注意：
    1 访问权限必须是public。
    2 函数名必须与类名相同。
    3 没有返回值，不写void。
    4 如果类中定义了拷贝构造函数，编译器将不提供默认的拷贝构造函数。
        编译器提供的拷贝构造和普通构造不一样，编译器提供的普通构造是空实现，
        而编译器提供的拷贝构造确实把值拷贝了
示例：*/

// 自己写一个默认拷贝构造，第一个参数必须是自己类的常引用
// 此时编译器将不再提供默认的拷贝构造
CBoy::CBoy(const CBoy &b)
{
    m_name = "漂亮的" + b.m_name;
    m_age = b.m_age - 1;
    cout << "调用了CBoy::CBoy(const CBoy &b)的拷贝构造" << endl;
}

void test105_copyconstruct()
{
    CBoy oldboy;
    oldboy.m_name = "老男孩";
    oldboy.m_age = 12;

    // 用一个已经有的对象给另外一个对象赋值，调用自带的拷贝构造
    // 方法1：
    CBoy newboy(oldboy);
    newboy.getter();

    // 方法2:
    // CBoy newboy = oldboy;
}

/*
    5 以值传递的方式调用函数时，如果实参为对象，会调用拷贝构造函数。
    6 （重要）函数以值的方式返回对象时，可能会调用拷贝构造函数（VS会调用，Linux不会，g++编译器做了优化）。
    7 拷贝构造函数可以重载，可以有默认参数。
        类名(......,const 类名& 对象名,......){......}
        下面是一个有参数的拷贝构造函数
*/
CBoy::CBoy(const CBoy &b, int ii)
{
    m_name = "漂亮的" + b.m_name;
    m_age = b.m_age - ii;
    cout << "调用了CBoy::CBoy(const CBoy &b,int ii)的拷贝构造" << endl;
}
void test105_copyconstruct2()
{
    CBoy b1;
    b1.setter("richard", 4);
    CBoy b2(b1, 1);
    b2.getter();
}

/*
    8 如果类中重载了拷贝构造函数却没有定义默认的拷贝构造函数，编译器也会提供默认的拷贝构造函数。

*/
void test105_bullet5(CBoy b)
{
    b.getter();
}

void test105_main()
{
    // test105_copyconstruct();
    CBoy b1;
    b1.m_age = 23;
    b1.m_name = "David";
    test105_bullet5(b1); // 把g1传进去，会调用一次拷贝构造。 形参上的构造
    test105_copyconstruct2();
}

int main()
{
    // test101_main();
    // test102_main();

    // test104_main();
    test105_main();
}