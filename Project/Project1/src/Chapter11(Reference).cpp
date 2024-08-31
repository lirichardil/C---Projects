#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*78、引用的基本概念

引用变量是C++新增的复合类型。
引用是已定义的变量的别名。
引用的主要用途是用作函数的形参和返回值。
声明/创建引用的语法：数据类型 &引用名=原变量名;

1	引用的数据类型要与原变量名的数据类型相同。
2	引用名和原变量名可以互换，它们值和内存单元是相同的。
3	必须在声明引用的时候初始化，初始化后不可改变。
4	C和C++用&符号来指示/取变量的地址，C++给&符号赋予了另一种含义。

*/
void test78_main()
{
    int a = 3;
    // int &ra; // 报错，必须初始化
    int &ra = a;
    // a和ra的地址和值都是一样的，也就是a的别名，可以呼唤。
    cout << "a的地址是" << &a << "a的值是" << a << endl;     // 3
    cout << "ra的地址是" << &ra << "ra的值是" << ra << endl; // 3

    ra = 8;
    cout << "a的地址是" << &a << "a的值是" << a << endl;     // 8
    cout << "ra的地址是" << &ra << "ra的值是" << ra << endl; // 8

    int b = 5;
    ra = b; // 将b的值赋值给ra，不是让ra成为b的别名

    cout << "a的地址是" << &a << "a的值是" << a << endl;     // 5
    cout << "ra的地址是" << &ra << "ra的值是" << ra << endl; // 5
}

/* 79 引用的本质
引用是指针常量的伪装。
指针常量的特点：
- int* const 变量名
- 定义时初始化，不然没有意义
- 可以通过解引用的方法修改内存地址中的值
- 指针常量指向的

引用是编译器提供的一个有用且安全的工具，去除了指针的一些缺点，禁止了部分不安全的操作。


变量是什么？变量就是一个在程序执行过程中可以改变的量。
换一个角度，变量是一块内存区域的名字，它代表了这块内存区域，当我们对变量进行修改的时候，会引起内存区域中内容的改变。
在计算机看来，内存区域根本就不存在什么名字，它仅有的标志就是它的地址，因此我们若想修改一块内存区域的内容，只有知道他的地址才能实现。
所谓的变量只不过是编译器给我们进行的一种抽象，让我们不必去了解更多的细节，降低我们的思维跨度而已。
程序员拥有引用，但编译器仅拥有指针（地址）。
引用的底层机制实际上是和指针一样的。不要相信有别名，不要认为引用可以节省一个指针的空间，因为这一切不会发生，编译器还是会把引用解释为指针。
引用和指针本质上没有区别。


*/

void test79_main()
{
    int a = 3;
    int &ra = a;
    int *const rb = &a;
    // 上面三个a,ra,rb 的值都是3，指向同一块内存。
    // 其中 int &ra = a 和 int *const rb 时等价的。
    cout << "a的地址是" << &a << " a的值是" << a << endl;     // 3
    cout << "ra的地址是" << &ra << " ra的值是" << ra << endl; // 3
    // 上面两端他们的地址是相同的，值都是3

    int b = 5;
    // rb = &b; //编译会报错，因为rb是指针常量，指针指向不可以改变，但是指针指向的值可以改变。
}

/*80、引用用于函数的参数
把函数的形参声明为引用，调用函数的时候，形参将成为实参的别名。

这种方法也叫按引用传递或传引用。（传值、传地址、传引用只是说法不同，其实都是传值。）
引用的本质是指针，传递的是变量的地址，在函数中，修改形参会影响实参。

1）传引用的代码更简洁。
2）传引用不必使用二级指针。
3）引用的属性和特别之处。

*/
void test80_func1(int no, string str) // 传值。
{
    cout << "fun1修改前形参号码：" << no << "号：" << str << endl;
    no = 8;               // 修改形参的值
    str = "fun1修改信息"; // 修改形参的值,但是并不会形象实参
    cout << "fun1修改后形参号码：" << no << "号：" << str << endl;
}

void test80_func2(int *no, string *str) // 传地址（传指针）
{
    cout << "fun2修改前形参号码：" << *no << "号：" << *str << endl;
    *no = 8;           // 修改地址上的值，原始的值也会被改变
    *str = "修改信息"; // 修改地址上的值，原始的值也会被改变
    cout << "fun2修改后形参号码：" << *no << "号：" << *str << endl;
}

void test80_func3(int &no, string &str) // 传引用，本质就是int* const no, string * str
{
    cout << "fun3修改前形参号码：" << no << "号：" << str << endl;
    no = 8;               // 修改引用的值，也就是修改地址，实参会改变
    str = "fun3修改信息"; //
    cout << "fun3修改后形参号码：" << no << "号：" << str << endl;
}

// 如果传入的是结构体，不需要写-> 符号，
struct Student
{
    int no;
    string str;
};
void test80_func4(Student stu) // 结构体传值
{
    stu.no = 8;
    stu.str = "func4结构体string";
    cout << "Func4 修改后 No:" << stu.no << " Func4 修改后 Message" << stu.str << endl;
}
void test80_func5(Student *stu) // 结构体传地址
{

    stu->no = 10; // stu是地址，所以需要->
    stu->str = "func5结构体内string";
    cout << "Func5 修改后  No:" << stu->no << "Func5修改后 Message" << stu->str << endl;
}
void test80_func6(Student &stu) // 结构体传引用
{
    stu.no = 20; // 引用可以直接用.
    stu.str = "func6结构体string";
    cout << "Func6 修改后 No:" << stu.no << " Func6 修改后 Message" << stu.str << endl;
}

// func7展示 引用的第二个作用，就是不需要传递二级指针。
// 在子函数中动态分配内存

void test80_func7(int **p) // 传入二级指针，来存放动态分配的内存地址
{
    *p = new int(3); // p是二级指针，存放指针的地址
    cout << "func7内存的地址是" << *p << "内存中的值是" << **p << endl;
}

// func8使用引用，实参是指针，形参是指针的别名
void test80_func8(int *&p) // 理解： int &p是 p的别名，int* &p 是指针p的地址（二级指针）
{
    p = new int(3); //
    cout << "func8 内存的地址是" << p << ",内存中的值是 " << *p << endl;
}

void test80_main()
{
    int bh = 3;                  // 超女的编号。
    string message = "原始信息"; // 向超女表白的内容。

    // test80_func1(bh, message); // 传值。
    // cout << "调用fun1后，\n 主函数中hb的值" << bh << "号：" << message << endl;//并没有有修改

    // test80_func2(&bh, &message);                                                // 传地址。
    // cout << "调用fun2后，\n 主函数中hb的值" << bh << "号：" << message << endl; // 并没有有修改

    // test80_func3(bh, message);
    // cout << "调用fun3后，\n 主函数中hb的值" << bh << "号：" << message << endl; // 并没有有修改

    Student stu = {10, "Main函数信息"};

    // test80_func4(stu);
    // cout << "调用Func4后,\n 主函数中 student.no 值为" << stu.no << "主函数中 stu.string = " << stu.str << endl;//不被修改

    // test80_func5(&stu);
    // cout << "调用Func5后,\n 主函数中 student.no 值为" << stu.no << "主函数中 stu.string = " << stu.str << endl;//被修改

    // test80_func6(stu);                                                                                          // 传值就可以了
    // cout << "调用Func6后,\n 主函数中 student.no 值为" << stu.no << "主函数中 stu.string = " << stu.str << endl; // 被修改

    // 业务需求，动态分配内存的工作需要在子函数中完成
    int *p = nullptr; // 存放在子函数中动态分配内存的地址。

    test80_func7(&p); // 传指针的地址，实参填指针p的地址。
    test80_func8(p);
    cout << "main 内存的地址是：" << p << "，内存中的值是：" << *p << endl;
    delete p;
}

/*81、引用的形参和const

const 的用途就是规定被修饰的变量，指针，形参不可改变


如果引用的数据对象类型不匹配，当引用为const时，C++将创建临时变量，让引用指向临时变量。
什么时候将创建临时变量呢？
- 引用是const。
- 数据对象的类型是正确的，但不是左值。
- 数据对象的类型不正确，但可以转换为正确的类型。

结论：如果函数的实参不是左值或与const引用形参的类型不匹配，那么C++将创建正确类型的匿名变量，将实参的值传递给匿名变量，并让形参来引用该变量。
将引用形参声明为const的理由有三个：
- 使用const可以避免无意中修改数据的编程错误。
- 使用const使函数能够处理const和非const实参，否则将只能接受非const实参。
- 使用const，函数能正确生成并使用临时变量。

什么是左值右值？
左值是可以被引用的数据对象，可以通过地址访问它们，例如：变量、数组元素、结构体成员、引用和解引用的指针。
非左值包括字面常量（用双引号包含的字符串除外）和包含多项的表达式。

*/

void test81_func1(int no, string str) // 传值。
{
    cout << "fun1形参号码：" << no << "号：" << str << endl;
}

void test81_func2(int *no, string *str) // 传地址（传指针）
{
    cout << "fun2形参号码：" << *no << "号：" << *str << endl;
}

void test81_func3(int &no, string &str) // 传引用，本质就是int* const no, string * str
{
    cout << "fun3形参号码：" << no << "号：" << str << endl;
}

void test81_func4(const int &no, const string &str) // 传引用，本质就是int* const no, string * str
{
    cout << "fun4形参号码：" << no << "号：" << str << endl;
}

void test81_main()
{
    int bh = 3;                  // 超女的编号。
    string message = "原始信息"; // 向超女表白的内容。

    // 有些情况我们不希望先创建变量，而是直接给函数传入常量
    test81_func1(5, "原始信息"); // 传值 不报错
    // 同样我们想给func2也传入常数，但是编译器并不允许
    // test81_func2(5, "原始信息"); // 传地址。
    // 同样我们想给func3也传入常数，但是编译器并不允许
    // test81_func3(5, "原始信息"); // 传引用。

    // 但是这样直接传常量的需求很普遍，怎么解决呢？
    // 如果引用的数据对象类型不匹配，当引用为const时，C++将创建临时变量，让引用指向临时变量。

    // int &ra = 9;       // 错误的，引用需要时地址，9是常量，根本没有地址
    const int &ra = 9; // 这样就可以了，因为c++做了特别处理
    // 相对于
    // int temp = 9;
    // const int &ra = temp;

    test81_func4(5, "原始信息"); // 成功
}

/* 82、引用用于函数的返回值

传统的函数返回机制与值传递类似。
函数的返回值被拷贝到一个临时位置（寄存器或栈），如果返回值很小，就放在寄存器里面
如果返回值大（超过8字节）就会放在栈里面。
然后调用者程序再使用这个值。

eg1:
double m=sqrt(36);      // sqrt()是求平方根函数。
sqrt(36)的返回值6被拷贝到临时的位置，然后赋值给m。

eg2:
cout << sqrt(25);
sqrt(25)的返回值5被拷贝到临时的位置，然后传递给cout。

eg3:
如果返回的是一个结构体，将把整个结构体拷贝到临时的位置。
如果返回引用不会拷贝内存。


语法：
返回值的数据类型& 函数名(形参列表);

    注意：
    - 如果返回局部变量的引用，其本质是野指针，后果不可预知。
    - 可以返回函数的引用形参、类的成员、全局变量、静态变量。
    - 返回引用的函数是被引用的变量的别名，将const用于引用的返回类型。

 */
int test82_func1() // 返回的是值，会临时拷贝，占用内存变量
{
    int ii = 3;
    return ii;
}
int &test82_func2() // 返回的值是引用
{
    // int ii = 3;
    static int ii = 3;
    return ii;
}

int &test82_func3(int &ra) // func3 返回的是一个引用形参
{
    ra++;
    cout << "ra 的地址是：" << &ra << " ra = " << ra << endl;
    return ra;
}

void test82_main() //
{
    int a = test82_func1();
    cout << "a= " << a << endl;
    // func1返回 的 ii 会先存放在一个寄存器中，再传给a

    int &b = test82_func2();     // 用引用接受返回值
    cout << "b = " << b << endl; // 返回一串奇怪的值。
    // 这是因为int& 返回的其实是ii 的地址(局部变量),但是在函数调用结束后，ii的地址就被释放了
    // ii就不存在了，这是返回的就是没有意义的值
    // 所以返回的这个值的周期应该要比函数的周期要长，
    // 比如是一个全局变量，或者是静态变量,类，或者引用形参

    int &c = test82_func3(a);
    cout << "a after func3 = " << a << endl;

    cout << "c 的地址是： " << &c << " c= " << c << endl;
    // c的地址和ra是一样的
}

/* 83 各种形参的使用场景 重要！！

使用场景主要分为两类，需要在子函数中修改形参和不需要在子函数中修改形参

1. 不需要修改实参
	如果实参很小，如C++内置的数据类型或小型结构体，则按值传递。
	如果实参是数组，则使用const指针，因为这是唯一的选择（没有为数组建立引用的说法）。
	如果实参是较大的结构，则使用const指针或const引用。
	如果实参是类，则使用const引用，传递类的标准方式是按引用传递（类设计的语义经常要求使用引用）。

2. 需要修改实参（不能加const约束）
	如果实参是内置数据类型，则使用指针。只要看到func(&x)的调用，表示函数将修改x。
	如果实参是数组，则只能使用指针。
	如果实参是结构体，则使用指针或引用。
	如果实参是类，则使用引用。
当然，这只是一些指导原则，很可能有充分的理由做出其他的选择。
例如：对于基本类型，cin使用引用，因此可以使用cin>>a，而不是cin>>&a。



*/

void test83_main()
{
}
int main()
{
    // test78_main();
    // test79_main();
    // test80_main();
    // test81_main();
    test82_main();
}