#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
/*70、结构体的基本概念

结构体是用户自定义的类型，可以将多种数据的表示合并到一起，描述一个完整的对象。

使用结构体有两个步骤：
1）定义结构体描述（类型）；

格式：

struct 结构体名
{
成员一的数据类型  成员名一;
成员二的数据类型  成员名二;
成员三的数据类型  成员名三;
......
成员n的数据类型  成员名n;
};

2）创建结构体变量。

说白了，结构体就是一个变量的工具箱，将不同的变量放在一起
一个结构体相当于告诉编译器我们创建了一个新的数据类型（就像int，double)
数据类型是不可以当成变量使用的，所以需要声明变量

创建结构体变量的语法：
struct 结构体名 结构体变量名;

也可以为结构体成员赋初始值：
struct 结构体名 结构体变量名={成员一的值, 成员二的值,......, 成员n的值};
C++11可以不写等于号。

如果大括号内未包含任何东西或只写一个0，全部的成员都将被设置为0。
struct 结构体名 结构体变量名={0};


注意：
	结构体名是标识符。
	结构体的成员可以是任意数据类型。
	定义结构体描述的代码可以放在程序的任何地方，一般放在main函数的上面或头文件中。
只有把结构体放在main函数上面，那整个程序都可以调用结构体
如果放在头文件中，使用的时候要把头文件包含进来


	结构体成员可以用C++的类（如string），但是不提倡。-后期解释
	在C++中，结构体中可以有函数，但是不提倡。
	在C++11中，定义结构体的时候可以指定缺省值。
    当我们创建结构体时，如果给里面的变量赋值，那他们就是缺省值
    否则则需要用户在创建结构体变量的是否赋值。
	在C++中，struct关键字可以不写。
	可以在定义结构体的时候创建结构体变量。



3）使用结构体
在C++程序中，用成员运算符（.）来访问结构体的每个成员。结构体中的每个成员具备普通变量的全部特征。
语法：结构体变量名.结构体成员名;


4) 占用内存大小
用sizeof运算符可以得到整个结构体占用内存的大小。
注意：整个结构体占用内存的大小不一定等于全部成员占用内存之和。
内存对齐：#pragma pack(字节数)
合理使用内存对齐规则，某些节省内存的做法可能毫无意义。在不同的编译器，规则不一样

5）清空结构体
创建的结构体变量如果没有初始化，成员中有垃圾值。//Linux不会报错，vs会
要养成初始化的习惯。
用memset()函数可以把结构体中全部的成员清零。（只适用于C++基本数据类型）
bzero()函数也可以。


6）复制结构体
	用memcpy()函数把结构体中全部的元素复制到另一个相同类型的结构体（只适用于C++基本数据类型）。
	也可以直接用等于号（只适用于C++基本数据类型）。



*/

void test70_main()
{
    // 定义结构体
    struct st_person
    {
        // string name = "Yijun"; //不推荐
        char name[21] = "Yijun"; // C风格
        int age = 25;
        double weight = 48.6;
        char sex = 'M';
    };
    struct st_person_2 // 没有指定缺省值，就会报错
    {
        // string name = "Yijun"; //不推荐
        char name[21];
        int age;
        double weight;
        char sex;
        bool gg;
    };

    struct st_person_3 // 在创建结构体的时候定义变量
    {
        // string name = "Yijun"; //不推荐
        char name[21] = "who";
        int age = 21;
        double weight = 100;
        char sex = 'f';
        bool gg = 1;
    } st_person3; // 创建结构体的时候定义变量

    cout << "姓名：" << st_person3.name << "年龄：" << st_person3.age << endl;

    struct st_person stperson; // c语言struct一定要写，c++不用。
    // 使用结构体
    cout << "姓名：" << stperson.name << "年龄：" << stperson.age << endl;

    struct st_person_2 st_person2 = {"Xinyi", 21, 14, 'F', 1};
    cout << "姓名：" << st_person2.name << "年龄：" << st_person2.age << endl;

    cout << sizeof(st_person_2) << endl; // 由于字节对齐的原因，不会完全等于所有之和

    // 清空结构体 memset(结构体变量的地址，0，结构体大小)
    memset(&st_person2, 0, sizeof(st_person2));
    // bzero(&st_person2, sizeof(st_person2))
    cout << "姓名：" << st_person2.name << "年龄：" << st_person2.age << endl;

    // 结构体复制
    st_person_2 st_person2_2{"Xinyi", 21, 14, 'F', 1};
    st_person2 = st_person2_2;
    cout << "姓名：" << st_person2.name << "年龄：" << st_person2.age << endl;
}

/*71、结构体指针
结构体是一种自定义的数据类型，用结构体可以创建结构体变量。

1）基本语法
在C++中，用不同类型的指针存放不同类型变量的地址，这一规则也适用于结构体。如下：
    struct st_girl girl;         // 声明结构体变量girl。
    struct st_girl *pst=&girl;  // 声明结构体指针，指向结构体变量girls。

通过结构体指针访问结构体成员，有两种方法：
 (*指针名).成员变量名    // (*pst).name和(*pst).age

或者：

指针名->成员变量名    // pst->name和*pst->age

在第一种方法中，圆点.的优先级高于*，(*指针名)两边的括号不能少。
如果去掉括号写成(*指针名).成员变量名，那么相当于*(指针名.成员变量名)，意义就完全不一样了。
在第二种方法中，->是一个新的运算符。
上面的两种方法是等效的，程序员通常采用第二种方法，更直观。
注意：与数组不一样，结构体变量名没有被解释为地址。



2）用于函数的参数
如果要把结构体传递给函数，实参取结构体变量的地址，函数的形参用结构体指针。
如果不希望在函数中修改结构体变量的值，可以对形参加const约束。

3）用于动态分配内存
用结构体指针指向动态分配的内存的地址。

*/

struct st_person
{
    // string name = "Yijun"; //不推荐
    char name[21] = "Yijun"; // C风格
    int age = 25;
    double weight = 48.6;
    char sex = 'M';
} st;

void test71_1(st_person *mp_st) // 如果不想被修改，可以加上const （cost st_person *mp_st）
{
    cout << "姓名：" << mp_st->name << " 年龄：" << mp_st->age << endl;
    // 因为传进来是实参的地址，所以可以改变实参的值

    mp_st->age = 88;
    strcpy(mp_st->name, "西瓜"); // 注意name是c风格字符串，不能用等号赋值
}

void test71_main()
{
    // 定义结构体的时候同时创建了结构体变量st

    // 定义结构体指针

    st_person *p_st = &st; // 将结构体变量额地址赋值给类结构体指针
    // 方法1 通过解引用操作结构体内的数据
    cout << "姓名：" << (*p_st).name << " 年龄：" << (*p_st).age << endl;
    // 方法2 通过箭头
    cout << "姓名：" << p_st->name << " 年龄：" << p_st->age << endl;

    test71_1(&st);
    cout << "姓名：" << p_st->name << " 年龄：" << p_st->age << endl; // 被修改成西瓜

    st_person *p_st_2 = new st_person({0});
    // 或者直接初始化的时候将初始值设置成0，而不是用memset函数

    memset(p_st_2, 0, sizeof(st_person));
    cout << "姓名：" << p_st_2->name << " 年龄：" << p_st_2->age << endl; // 被修改成西瓜
    delete p_st_2;
}

/*72、结构体数组

结构体可以被定义成数组变量，本质上与其它类型的数组变量没有区别。
声明结构体数组的语法：struct 结构体类型 数组名[数组长度];

初始化结构体数组，要结合使用初始化数组的规则和初始化结构体的规则。
struct st_girl girls[2]={{"西施",26,43.8,'X',true},{"西瓜",25,52.8,'X',false}};

使用结构体数组可以用数组表示法，也可以用指针表示法。

*/

void test72_main()
{
    // 结构体数组变量初始化
    st_person st_array[3];
    memset(&st_array, 0, sizeof(st_array));
    strcpy(st_array[0].name, "Yijun"); // c风格字符用strcpy函数
    st_array[0].age = 25;
    st_array[0].sex = 'F'; // 逐个通过st_array赋值

    // st_array[1] = {"Xinyi", 2, 10.6, 'Y'}; // C11标准语法
    // 使用指针表示法：
    // *(st_array + 1) = {"Xinyi", 2, 10.6, 'Y'};
    // st_array[2] = {"Yuki", 3, 4.4, 'X'};

    for (int i = 0; i < 3; i++)
    {
        cout << "第" << i << "个结构体数组元素的是姓名是" << st_array[i].name << " 年龄是" << st_array[i].age << endl;
    }
}

/*73、结构体嵌入数组和结构体
结构体中可以嵌入任何数据类型的成员，除了他自己。

1. 结构体中嵌入多维数组，可以避开多维数组函数传参中使用到的多指针的问题（件test73_1)
2. 结构体中不能嵌套自己


*/

struct st_pet;
struct st_person2
{
    int score[2][3] = {0}; // 有一个多维数组
    // struct st_pet pet; 会报错
    st_pet *p_st_pet;
};
// 在C语言中，当你提前声明一个结构体类型时，
// 该类型在声明时被视为“不完全类型”（incomplete type），即它的内存布局尚未确定。因此，不允许直接在另一个结构体中定义一个该类型的成员，
// 而只能使用指向该结构体的指针。

struct st_pet
{
    char name[21]; // 宠物的名字
    char type[21]; // 宠物的种类
};

void test73_1(st_person2 *m_p_person)
{
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "m_p_person->score[" << ii << "]" << "[" << jj << "]=" << m_p_person->score[ii][jj] << endl;
        }
    }
}

void test73_2(void)
{
    // st_person2 person = {{0}, {"宠物的名字", "宠物的种类"}};行不通，因为pet是一个指针
    st_person2 person = {{0}};
    //  需要动态分配内存给st_pet并初始化
    person.p_st_pet = (struct st_pet *)malloc(sizeof(struct st_pet));
    if (person.p_st_pet != NULL)
    {
        strcpy(person.p_st_pet->name, "宠物的名字");
        strcpy(person.p_st_pet->type, "宠物的种类");
    }

    for (int ii = 0; ii < 2; ii++)
    {
        cout << "person.p_st_pet->name = " << person.p_st_pet->name << "person.p_st_pet->type is " << person.p_st_pet->type << endl;
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "person->score[" << ii << "]" << "[" << jj << "]=" << person.score[ii][jj] << endl;
        }
    }
    free(person.p_st_pet);
}

void test73_main()
{
    st_person2 person2;
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            person2.score[ii][jj] = 100 + ii;
        }
    }
    for (int ii = 0; ii < 3; ii++)
    {
        cout << "Person2 scores are" << person2.score[ii] << endl;
    }

    // test73_1(&person2);
    test73_2();
}

/* 74、结构体中的指针 （重要）

结构体的成员可以使用指针，但是如果这个指针指向的是动态分配的内存地址（new),那么对
结构体使用sizeof运算可能就没有意义，而且用memset（）函数可能会造成泄露。

1. sizeof 只会算出指针的大小，不会找到指针所指向空间的大小
2. memset 会将指针的地址设置为 00000000， 没有办法调用new 出来的函数了，造成了野指针。
3. C++字符串string中有一个指向的是动态分配的内存地址指针，所以如果结构体的成员是string就要小心了
*/
struct st_t
{
    int a;
    int *p; // 结构体内的指针
};

struct Person
{
    string name;
};

void test74_main()
{
    st_t stt;             // 创建结构体变量
    stt.p = new int[100]; // 动态创建一个长度为100 的int数组，stt.p指向该数组
    stt.a = 3;

    cout << "sizeof(stt)" << sizeof(stt) << endl; // 得到的结果是16.这是因为内存对齐的原因
    // int占4个字节， int* 占4个字节，但是编译器8位寻址，所以占用16个字节。
    // 但是这样并没有意义

    cout << "stt.a=" << stt.a << "stt.p = " << stt.p << endl;
    memset(&stt, 0, sizeof(st_t)); // 对结构体进行清0就会把*p的地址修改成 0000，就出现了野指针。
    cout << "stt.a=" << stt.a << "stt.p = " << stt.p << endl;

    // 正确的是
    memset(stt.p, 0, 100 * sizeof(int));
    delete[] stt.p;

    Person Richard;
    Richard.name = "Yijun";
    // memset(&Richard,0,sizeof(Richard)); 这行代码将 Richard 里面的string 里维护的指针也设置成了0
}
/* 75 简单链表
如果结构体中有一个本结构体的指针，它就是链表。

1. 链表的每一个节点都是静态分配出来的内存，没有静态的说法，静态的是数组。

*/
struct node // 链表
{
    int number;
    string name;
    struct node *next; // 下一个节点的地址，如果是最后一个next为空
};

void test75_main()
{
    node *head = nullptr, *tail = nullptr, *temp = nullptr;
    // 分配第一个节点,让零时指针指向这个节点
    temp = new node;
    // 为这个节点赋值,有三种方法
    // 第一种
    temp->number = 1;
    temp->name = "RIchard";
    temp->next = nullptr;
    // 第二种 C11标准写法
    *(temp) = {1, "Richard", nullptr};
    // 第三种，在new的时候就分配
    // temp = new node({1,"Richard",nullptr});

    // 让头指针和尾指针都指向他
    head = tail = temp;

    // 分配第二个节点：

    temp = new node({2, "Lily", nullptr});
    tail->next = temp;
    tail = temp;

    // 分配第三个界定啊
    temp = new node({3, "Vivi", nullptr});
    tail->next = temp;
    tail = temp;

    // 遍历链表
    temp = head;
    while (temp != nullptr)
    {
        cout << "no=" << temp->number << "name=" << temp->name << "tmp->next=" << temp->next << endl;
        temp = temp->next; // 顺着next往后面找
    }

    // 删除节点
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/*76、共同体/联合体
共同体（共用体、联合体）是一种数据格式，
它能存储不同的数据类型，但是，在同一时间只能存储其中的一种类型。
“有一种选项”

union 共同体名
{
成员一的数据类型  成员名一;
成员二的数据类型  成员名二;
成员三的数据类型  成员名三;
......
成员n的数据类型  成员名n;
};

注意：
	共同体占用内存的大小是它最大的成员占用内存的大小（内存对齐）。
	全部的成员使用同一块内存。
	共同体中的值为最后被赋值的那个成员的值。
	匿名共同体没有名字，可以在定义的时候创建匿名共同体变量（VS和Linux有差别，vs不可以，linux可以），也可以嵌入结构体中。

应用场景：
	当数据项使用两种或更多种格式（但不会同时使用）时，可节省空间（嵌入式系统）。
	用于回调函数的参数（相当于支持多种数据类型）。


*/

union udata // 声明共同体udata。
{
    int a;
    double b;
    char c[25];
} data;

void test76_test1()
{
    // udata data; //定义共同体变量
    cout << "sizeof(data)=" << sizeof(data) << endl;

    // 全部的成员使用同一块内存。
    cout << "data.a的地址是：" << (void *)&data.a << endl;
    cout << "data.b的地址是：" << (void *)&data.b << endl;
    cout << "data.c的地址是：" << (void *)&data.c << endl;

    // 赋值-共同体中的值为最后被赋值的那个成员的值。
    // data.a = 3;
    data.b = 8.8;
    // strcpy(data.c, "我是一只傻傻鸟。");
    cout << "data.a=" << data.a << endl;
    cout << "data.b=" << data.b << endl;
    cout << "data.c=" << data.c << endl;

    // 为哪个值赋值，其他的值就失去了意义，只会有被赋值的那个值有意义。
}

struct test76
{
    int no;
    union
    {
        int a;
        double b;
        char c[21];
    };
};
void test76_test2()
{
    test76 testcase;
    cout << testcase.a << testcase.b << testcase.c << endl; // 嵌套共同体成员作为struct成员直接使用
}

// Define a union to hold different types of data
union Data
{
    int intValue;
    float floatValue;
    char charValue;
};

// Define a callback function type that takes a union as a parameter
typedef void (*Callback)(Data);

// Example callback functions
void handleInt(Data data)
{
    std::cout << "Handling int: " << data.intValue << std::endl;
}

void handleFloat(Data data)
{
    std::cout << "Handling float: " << data.floatValue << std::endl;
}

void handleChar(Data data)
{
    std::cout << "Handling char: " << data.charValue << std::endl;
}

// Function to trigger callback
void triggerCallback(Callback callback, Data data)
{
    callback(data);
}
void test76_test3() // Union作为回调函数参数
{
    Data data;

    // Use int type
    data.intValue = 42;
    triggerCallback(handleInt, data);

    // Use float type
    data.floatValue = 3.14f;
    triggerCallback(handleFloat, data);

    // Use char type
    data.charValue = 'A';
    triggerCallback(handleChar, data);
}

void test76_main()
{
    test76_test1();
    test76_test2();
    test76_test3();
}

/*77.枚举
枚举是一种创建符号常量的方法。
枚举的语法：

enum 枚举名 { 枚举量1 , 枚举量2 , 枚举量3, ......, 枚举量n };
例如：
enum colors { red , yellow , blue };

这条语句完成了两项工作：
-	让colors成了一种新的枚举类型的名称，可以用它创建枚举变量。
-	将red、yellow、blue作为符号常量，默认值是整数的0、1、2。


注意：
-	用枚举创建的变量取值只能在枚举量范围之内。
-	枚举的作用域与变量的作用域相同。
-	可以显式的设置枚举量的值（必须是整数）。
-	可以显式的设置枚举量的值（必须是整数）。
enum colors {red=1,yellow=2,blue=3};
-	可以只显式的指定某些枚举量的值（枚举量的值可以重复）。
enum colors {red=10,yellow,blue};
-	可以将整数强制转换成枚举量，语法：枚举类型(整数)


*/

void test77_main()
{
    enum colors
    {
        red = 0,
        yellow = 1,
        blue = 2,
        other = 3
    }; // 创建枚举类型colors。

    colors cc = yellow; // 创建枚举变量，并赋初始值。
    // colors cc = colors(1);           // 创建枚举变量，并赋初始值。

    cout << "red=" << red << ",yellow=" << yellow << ",blue=" << blue << ",other=" << other << endl;

    // cin >> cc;//cin 的>> 无法直接读 colors类型
    int input;
    cin >> input;
    colors aa = colors(input);
    switch (aa)
    {
    case red:
        cout << "红色。\n";
        break;
    case yellow:
        cout << "黄色。\n";
        break;
    case blue:
        cout << "蓝色。\n";
        break;
    default:
        cout << "未知。\n";
    }
}
int main()
{
    // test70_main();
    // test71_main();
    // test72_main();
    // test73_main();
    // test74_main();
    // test75_main();
    // test76_main();
    // test77_main();
}