#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*61. 一维数组的基本概念
数组是一组数据类型相同的变量，可以存放一组数据。


1）创建数组
声明数组的语法：数据类型 数组名[数组长度];
注意：数组长度必须是整数，可以是常量，也可以是变量和表达式。
C90规定必须用常量表达式指明数组的大小，C99允许使用整型非常量表达式。经测试，在VS中可以用用整型非常量表达式，
不能用变量；但是，Linux中还可以用变量。


2）数组的使用
可以通过下标访问数组中元素，数组下标从0开始。
数组中每个元素的特征和使用方法与单个变量完全相同。
语法：数组名[数组下标]
注意：
- 数组下标也必须是整数，可以是常量，也可以是变量。
- 合法的数组下标取值是：0~(数组长度-1)。


3）数组占用内存的情况
数组在内存中占用的空间是连续的。
用sizeof(数组名)可以得到整个数组占用内存空间的大小（只适用于C++基本数据类型）。

4）数组的初始化
声明的时候初始化：
数据类型 数组名[数组长度] = { 值1，值2，值3, ...... , 值n};
数据类型 数组名[ ] = { 值1，值2，值3, ...... , 值n};
数据类型 数组名[数组长度] = { 0 };  // 把全部的元素初始化为0。
数据类型 数组名[数组长度] = { };    // 把全部的元素初始化为0。
注意：如果{}内不足数组长度个数据，剩余数据用0补全，但是，不建议这么用，你可能在数组中漏了某个值。如果想把数组中全部的元素初始化为0，可以在{}内只填一个0或什么也不填。
    C++11标准可以不写等于号。


5）清空数组
用memset()函数可以把数组中全部的元素清零。（只适用于C++基本数据类型）
函数原型：void *memset(void *s, int c, size_t n);
注意，在Linux下，使用memcpy()函数需要包含头文件#include <string.h>


6）复制数组
用memcpy()函数可以把数组中全部的元素复制到另一个相同大小的数组。（只适用于C++基本数据类型）
函数原型：void *memcpy(void *dest, const void *src, size_t n);
注意，在Linux下，使用memcpy()函数需要包含头文件#include <string.h>

*/

void test61_main()
{
    // 1）创建数组
    int bh[3];

    // 2) 使用数组
    bh[0] = 3;
    bh[1] = 8;
    bh[2] = 5;

    // 3) 数组的占用内存情况
    cout << sizeof(bh) << endl;
    for (int i = 0; i < (sizeof(bh) / sizeof(int)) - 1; i++)
    {
        cout << bh[i] << endl;
    }

    // 4）数组的初始化
    // 声明的时候初始化：
    // 数据类型 数组名[数组长度] = { 值1，值2，值3, ...... , 值n};
    // 数据类型 数组名[ ] = { 值1，值2，值3, ...... , 值n};
    // 数据类型 数组名[数组长度] = { 0 };  // 把全部的元素初始化为0。
    // 数据类型 数组名[数组长度] = { };    // 把全部的元素初始化为0。
    // 注意：如果{}内不足数组长度个数据，剩余数据用0补全，但是，不建议这么用，你可能在数组中漏了某个值。如果想把数组中全部的元素初始化为0，可以在{}内只填一个0或什么也不填。
    //     C++11标准可以不写等于号。
    string name[] = {"hello", "hi", "hey"}; // 3 可以不填

    for (int i = 0; i < sizeof(name) / sizeof(string); i++)
    {
        cout << name[i] << endl;
    }

    // 5. 清空数组
    // 用memset()函数可以把数组中全部的元素清零。（只适用于C++基本数据类型）

    // 6. 复制数组
}
/* 62. 一维数组和指针

1. 指针的算术
    将一个整型变量加1后，其值将增加1。
    但是，将指针变量（地址的值）加1后，增加的量等于它指向的数据类型的字节数。

2. 数组的地址
    a）数组在内存中占用的空间是连续的。
    b）C++将数组名解释为数组第0个元素的地址。
    c）数组第0个元素的地址和数组首地址的取值是相同的。
    d）数组第n个元素的地址是：数组首地址+n
    e）C++编译器把   数组名[下标]  解释为  *(数组首地址+下标)

3. 数组的本质
数组是占用连续空间的一块内存，数组名被解释为数组第0个元素的地址。
C++操作这块内存有两种方法：数组解释法和指针表示法，它们是等价的。

4. 数组名不一定会被解释为地址
在多数情况下，C++将数组名解释为数组的第0个元素的地址，但是，将sizeof运算符用于数据名时，将返回整个数组占用内存空间的字节数。
可以修改指针的值，但数组名是常量，不可修改。

*/

void test62_1() // 指针的算术
{
    char a;
    cout << "sizeof(char)=" << sizeof(char) << endl;
    short b;
    cout << "sizeof(short)=" << sizeof(short) << endl;
    int c;
    cout << "sizeof(int)=" << sizeof(int) << endl;
    double d;
    cout << "sizeof(double)=" << sizeof(double) << endl;

    cout << "a的地址是：" << (void *)&a << endl; // 添加void* 可以让cout正确输出地址，而不是当成字符串
    cout << "a的地址+1是：" << (void *)(&a + 1) << endl;
    // a 是char， +1之后增加的量1
    cout << "b的地址是：" << (void *)&b << endl;
    cout << "b的地址+1是：" << (void *)(&b + 1) << endl;
    // b 是short， +1之后 增加的量是2
    cout << "c的地址是：" << (void *)&c << endl;
    cout << "c的地址+1是：" << (void *)(&c + 1) << endl;
    // c 是int， +1之后 增加的量是4

    cout << "d的地址是：" << (void *)&d << endl;
    cout << "d的地址+1是：" << (void *)(&d + 1) << endl;
}

void test62_2() // 数组的地址
{
    double a[5];

    cout << "a的值是：" << (long long)a << endl;
    cout << "&a的值是：" << (long long)&a << endl;

    cout << "a[0]的地址是：" << (long long)&a[0] << endl;
    cout << "a[1]的地址是：" << (long long)&a[1] << endl;
    cout << "a[2]的地址是：" << (long long)&a[2] << endl;
    cout << "a[3]的地址是：" << (long long)&a[3] << endl;
    cout << "a[4]的地址是：" << (long long)&a[4] << endl;

    double *p = a;
    cout << "p的值是：" << (long long)p << endl;
    cout << "p+0的值是：" << (long long)(p + 0) << endl;
    cout << "p+1的值是：" << (long long)(p + 1) << endl;
    cout << "p+2的值是：" << (long long)(p + 2) << endl;
    cout << "p+3的值是：" << (long long)(p + 3) << endl;
    cout << "p+4的值是：" << (long long)(p + 4) << endl;
}

void test62_3() // 数组的本质
{
    int a[5] = {3, 6, 5, 8, 9};

    // 用数组表示法操作数组。
    cout << "a[0]的值是：" << a[0] << endl;
    cout << "a[1]的值是：" << a[1] << endl;
    cout << "a[2]的值是：" << a[2] << endl;
    cout << "a[3]的值是：" << a[3] << endl;
    cout << "a[4]的值是：" << a[4] << endl;

    // 用指针表示法操作数组。
    int *p = a;
    cout << "*(p+0)的值是：" << *(p + 0) << endl;
    cout << "*(p+1)的值是：" << *(p + 1) << endl;
    cout << "*(p+2)的值是：" << *(p + 2) << endl;
    cout << "*(p+3)的值是：" << *(p + 3) << endl;
    cout << "*(p+4)的值是：" << *(p + 4) << endl;
}
void test62_main()
{
    test62_1();
}

/* 63. 一维数组用于函数的参数

1. 指针的数组表示
在C++内部，用指针来处理数组。
C++编译器把   数组名[下标]  解释为  *(数组首地址+下标)
C++编译器把   地址[下标]  解释为  *(地址+下标)

2. 一维数组用于函数的参数
一维数组用于函数的参数时，只能传数组的地址，并且必须把数组长度也传进去，
除非数组中有最后一个元素的标志。

书写方法有两种：
void func(int* arr, int len);
void func(int arr[], int len);

*/

void test63_1()
{
    char a[20];
    int *p = (int *)a;             // 让指针p指向数组a
    for (int ii = 0; ii < 6; ii++) // char a[20] 有20个字节，一个整形占4字节，char a[20]可以放5个int
    {
        p[ii] = ii + 300; // 用数组表述法操作指针
    }
    for (int ii = 0; ii < 6; ii++)
    {

        cout << "*(p+" << ii << ")的值是" << (*p + ii) << endl;
    }
}

void test63_2(int arr[], int len)
{
    cout << "sizeof(arr)" << sizeof(arr) << endl; // sizeof对指针的解释是指针的大小（8）
    for (int ii = 0; ii < len; ii++)
    {
        cout << "arr[" << ii << "]的值是：" << arr[ii] << endl;       // 用数组表示法操作指针。
        cout << "*(arr+" << ii << ")的值是：" << *(arr + ii) << endl; // 地址[下标] 解释为 *（地址+下标）
    }
}
void test63_main()
{
    test63_1();
    int a[] = {2, 8, 4, 6, 7, 1, 9};
    test63_2(a, sizeof(a) / sizeof(int));
    cout << "sizeof(a)" << sizeof(a) << endl; // sizeof对数组名的解释是取数组的大小
}

/*
64、用new动态创建一维数组
普通数组在栈上分配内存，栈很小；如果需要存放更多的元素，必须在堆上分配内存。
动态创建一维数组的语法：数据类型 *指针=new 数据类型[数组长度];
释放一维数组的语法：delete [] 指针;

注意
- 动态创建的数组没有数组名，不能用sizeof运算符。
- 可以用数组表示法和指针表示法两种方式使用动态创建的数组。
- 必须使用delete[]来释放动态数组的内存（不能只用delete）。
- 不要用delete[]来释放不是new[]分配的内存。
- 不要用delete[]释放同一个内存块两次（否则等同于操作野指针）。
- 对空指针用delete[]是安全的（释放内存后，应该把指针置空nullptr）。
- 声明普通数组的时候，数组长度可以用变量，相当于在栈上动态创建数组，并且不需要释放。
- 如果内存不足，调用new会产生异常，导致程序中止；如果在new关键字后面加(std::nothrow)选项，则返回nullptr，不会产生异常。
为什么用delete[]释放数组的时候，不需要指定数组的大小？因为系统会自动跟踪已分配数组的内存。


*/

void test64_main()
{
    int *arr = new int[8];
    for (int ii = 0; ii < 8; ii++)
    {
        arr[ii] = 100 + ii;                                    // 用数组表示
        cout << "*(arr+" << ii << ")=" << *(arr + ii) << endl; // 用指针表示
    }
    delete[] arr;
}

/*65、一维数组的排序qsort
qsort()函数用于对各种数据类型的数组进行排序。

函数的原型：
    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

    第一个参数：数组的起始地址，一般填数组名字
    第二个参数：数组元素的个数（数组长度）。
    第三个参数：数组元素的大小（sizeof(数组的数据类型)）。
    第四个参数：回调函数的地址。
    回调函数决定了排序的顺序，声明如下：

int compar(const void *p1, const void *p2);
1）如果函数的返回值< 0 ，那么p1所指向元素会被排在p2所指向元素的前面。
2）如果函数的返回值==0，那么p1所指向元素与p2所指向元素的顺序不确定。
3）如果函数的返回值> 0 ，那么p1所指向元素会被排在p2所指向元素的后面。

    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

qsort()函数的其它细节：

- 形参中的地址用void是为了支持任意数据类型，在回调函数中必须具体化。(否则不能解引用)
- 为什么需要第三个形参size_t size？
    size_t是C标准库中定义的，在64位系统中是8字节无符号整型（unsigned long long）。
    typedef unsigned long long size_t

- 排序的需求除了升序和降序，还有很多不可预知的情况，只能用回调函数。


*/

int CompAsc(const void *p1, const void *p2)
{
    // if((*p1)<(*p2)) return -1;//错误的，对void解引用必须是具体类型的指针
    if (*(int *)p1 < *(int *)p2)
        return -1;
    if (*(int *)p1 == *(int *)p2)
        return 0;
    if (*(int *)p1 > *(int *)p2)
        return 1;
    // 或者直接用下面这行代码代替
    //  return *((int*)p1) - *((int*)p2);
}

void test65_main()
{

    int a[5] = {4, 5, 8, 5, 8};
    // void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
    qsort(a, sizeof(a) / sizeof(int), sizeof(int), CompAsc);
    for (int ii = 0; ii < 5; ii++)
    {
        cout << "a[" << ii << "]=" << a[ii] << endl;
    }
}

/*66、一维数组的查找-折半查找
折半查找也叫二分查找，只适用于已排序的数组（升序降序都可以）。

*/

int BinarySearch(int a[], int len, int key)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] < key)
            left = mid + 1;
        else if (a[mid] > key)
            right = mid - 1;
        else
            return mid;
    }
    if (a[left] == key)
        return left;
    else if (a[right] == key)
        return right;
    else
        return -1;
}

void test66_main()
{
    int a[10] = {7, 9, 12, 16, 21, 25, 29, 30, 41, 48};
    cout << BinarySearch(a, 10, 30) << endl;
}

/*67、C风格的字符串

C++的字符串是string， 是一个类，很多功能都帮我们封装了。
语言约定：如果字符型（char）数组的末尾包含了空字符\0（也就是0），
那么该数组中的内容就是一个字符串。

eg: 这是一个字符数组，不是字符串
www.freecplus.net

这是一个字符数组，也是一个字符串
www.freecplus.net\0

因为字符串需要用0结尾，所以在声明字符数组的时候，要预留多一个字节用来存放0。
char name[21];  // 声明一个最多存放20个英文字符或十个中文的字符串。

1. ）初始化方法
char name[11];                 // 可以存放10个字符，没有初始化，里面是垃圾值。
char name[11] = "hello";         // 初始内容为hello，系统会自动添加0。
char name[]   = { "hello" };      // 初始内容为hello，系统会自动添加0，数组长度是6。
char name[11] = { "hello" };      // 初始内容为hello，系统会自动添加0。
char name[11]   { "hello" };      // 初始内容为hello，系统会自动添加0。C++11标准。
char name[11] = { 0 };          // 把全部的元素初始化为0。

2）清空字符串
memset(name,0,sizeof(name));   // 把全部的元素置为0。
name[0]=0;       // 不规范，有隐患，不推荐。

3）字符串复制或赋值strcpy()
c++可以用= 赋值， c风格则需要用strcpy
char *strcpy(char* dest, const char* src);
功 能: 将参数src字符串拷贝至参数dest所指的地址。
返回值: 返回参数dest的字符串起始地址。
复制完字符串后，会在dest后追加0。
如果参数dest所指的内存空间不够大，会导致数组的越界。

4）字符串复制或赋值strncpy()
char * strncpy(char* dest,const char* src, const size_t n);
功能：把src前n个字符的内容复制到dest中。
返回值：dest字符串起始地址。
如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。
如果参数dest所指的内存空间不够大，会导致数组的越界。

5）获取字符串的长度strlen()
 size_t  strlen( const char*  str);
功能：计算字符串的有效长度，不包含0。
返回值：返回字符串的字符数。
strlen()函数计算的是字符串的实际长度，遇到0结束。

6）字符串拼接strcat(）
char *strcat(char* dest,const char* src);
功能：将src字符串拼接到dest所指的字符串尾部。
返回值：返回dest字符串起始地址。
dest最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。
如果参数dest所指的内存空间不够大，会导致数组的越界。

7）字符串拼接strncat()
char *strncat (char* dest,const char* src, const size_t n);
功能：将src字符串的前n个字符拼接到dest所指的字符串尾部。
返回值：返回dest字符串的起始地址。
如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部，如果n小于字符串src的长度，只追加src的前n个字符。
strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。
如果参数dest所指的内存空间不够大，会导致数组的越界。

8）字符串比较strcmp()和strncmp()
int strcmp(const char *str1, const char *str2 );
功能：比较str1和str2的大小。
返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
int strncmp(const char *str1,const char *str2 ,const size_t n);
功能：比较str1和str2前n个字符的大小。
返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
两个字符串比较的方法是比较字符的ASCII码的大小，从两个字符串的第一个字符开始，如果分不出大小，就比较第二个字符，如果全部的字符都分不出大小，就返回0，表示两个字符串相等。
在实际开发中，程序员一般只关心字符串是否相等，不关心哪个字符串更大或更小。

9）查找字符strchr()和strrchr()
const char *strchr(const char *s, int c);
返回在字符串s中第一次出现c的位置，如果找不到，返回0。
const char *strrchr(const char *s, int c);
返回在字符串s中最后一次出现c的位置，如果找不到，返回0。
10）查找字符串strstr()
char *strstr(const char* str,const char* substr);
功能：检索子串在字符串中首次出现的位置。
返回值：返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回0。
11）用于string的表达式
可以把C风格的字符串用于包含了string类型的赋值拼接等表达式中。

12）注意事项
a）字符串的结尾标志是0，按照约定，在处理字符串的时候，会从起始位置开始搜索0，一直找下去，找到为止（不会判断数组是否越界）。
b）结尾标志0后面的都是垃圾内容。
c）字符串在每次使用前都要初始化，减少入坑的可能，是每次，不是第一次。(重要！！)
d）不要在子函数中对字符指针用sizeof运算，所以，不能在子函数中对传入的字符串进行初始化，
除非字符串的长度也作为参数传入到了子函数中。
e）在VS中，如果要使用C标准的字符串操作函数，要在源代码文件的最上面加
#define _CRT_SECURE_NO_WARNINGS


*/

void test67_main()
{
    char name[11];

    memset(name, 0, sizeof(name));
    // name[0] = 0;
    // strcpy(name, "hello");
    strncpy(name, "hello", 3);

    cout << "name=" << name << endl;

    cout << "name[0]=" << (int)name[0] << endl;
    cout << "name[1]=" << (int)name[1] << endl;
    cout << "name[2]=" << (int)name[2] << endl;
    cout << "name[3]=" << (int)name[3] << endl;
    cout << "name[4]=" << (int)name[4] << endl;
    cout << "name[5]=" << (int)name[5] << endl;
    cout << "name[6]=" << (int)name[6] << endl;
    cout << "name[7]=" << (int)name[7] << endl;
    cout << "name[8]=" << (int)name[8] << endl;
    cout << "name[9]=" << (int)name[9] << endl;
    cout << "name[10]=" << (int)name[10] << endl;
}

/*68、二维数组
一维数组的数学概念是线性表，二维数组的数学概念是矩阵。

1）创建二维数组
声明二维数组的语法：数据类型 数组名[行数][列数];
注意：数组长度必须是整数，可以是常量，也可以是变量和表达式。
C90规定必须用常量表达式指明数组的大小，C99允许使用整型非常量表达式。
经测试，在VS中可以用用整型非常量表达式，不能用变量；但是，Linux中还可以用变量。

2）二维数组的使用
可以通过行下标和列下标访问二维数组中元素，下标从0开始。
二维数组中每个元素的特征和使用方法与单个变量完全相同。
语法：数组名[行下标][列下标]
注意：
	二维数组下标也必须是整数，可以是常量，也可以是变量。
	合法的行下标取值是：0~(行数-1)。
	合法的列下标取值是：0~(列数-1)。

3）二维数组占用内存的情况
用sizeof(数组名)可以得到整个二维数组占用内存空间的大小（只适用于C++基本数据类型）。
二维数组在内存中占用的空间是连续的。


4）二维数组的初始化
声明的时候初始化：
数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 },...... };
数据类型 数组名[行数][列数] = { 数据1，数据2，数据3，数据4, ......};
数据类型 数组名[ ][列数] = { 数据1，数据2，数据3，数据4,......};
数据类型 数组名[行数][列数] = { 0 };  // 把全部的元素初始化为0。
数据类型 数组名[行数][列数] = { };    // 把全部的元素初始化为0。
注意：如果{}内不足数组长度个数据，剩余数据用0补全，但是，不建议这么用，你可能在数组中漏了某个值。如果想把数组中全部的元素初始化为0，可以在{}内只填一个0或什么也不填。
    C++11标准可以不写等于号。

5）清空二维数组
用memset()函数可以把二维数组中全部的元素清零。（只适用于C++基本数据类型）
函数原型：void *memset(void *s, int c, size_t n);
注意，在Linux下，使用memcpy()函数需要包含头文件#include <string.h>

6）复制二维数组
用memcpy()函数可以把二维数组中全部的元素复制到另一个相同大小的数组（没说多少维）。（只适用于C++基本数据类型）
函数原型：void *memcpy(void *dest, const void *src, size_t n);
注意，在Linux下，使用memcpy()函数需要包含头文件#include <string.h>

*/

void test67_main()
{
    // int bh[2][3] = { {11,12,13},{21,22,23} };                              // 声明一个两行三列的二维数组，存放超女的编号。
    // int bh[2][3] = { 11,12,13,21,22,23 };
    int bh[][3] = {11, 12, 13, 21, 22, 23};

    /*bh[0][0] = 11;		bh[0][1] = 12;    bh[0][2] = 13;
    bh[1][0] = 21; 	bh[1][1] = 22;    bh[1][2] = 23;*/

    /*cout << "bh[0][0] = " << bh[0][0] << "  bh[0][1] = " << bh[0][1] << "  bh[0][2] = " << bh[0][2] << endl;
    cout << "bh[1][0] = " << bh[1][0] << "  bh[1][1] = " << bh[1][1] << "  bh[1][2] = " << bh[1][2] << endl;*/

    for (int ii = 0; ii < 2; ii++) // 第一层循环表示行数，循环继续的条件是计数器小于行数。
    {
        for (int jj = 0; jj < 3; jj++) // 第二层循环表示列数，循环继续的条件是计数器小于列数。
        {
            cout << "&bh[" << ii << "][" << jj << "] = " << (long long)&bh[ii][jj] << "  "; // 处理二维数组的每个元素。
        }
        cout << endl; // 每处理一行数据后，输出一个换行。
    }

    int *p = (int *)bh;

    for (int ii = 0; ii < 6; ii++)
    {
        cout << "p[" << ii << "]=" << p[ii] << endl; // 一维数组的数组表示法。
    }
}
/*69、二维数组用于函数的参数

本节会引入一个新的概念，就是行指针。 在学习行指针前，我们复习一下我们学过的指针。
int* p;
int* p[3];   // 一维整型指针数组，元素是3个整型指针（p[0]、p[1]、p[2]）。
int* p();    // 函数p的返回值类型是整型的地址。
int (*p)(int ,int);   // p是函数指针，函数的返回值是整型。

1）行指针（数组指针）

数据类型 (*行指针名)[行的大小];  // 行的大小即数组长度。
int (*p1)[3];  // p1是行指针，用于指向数组长度为3的int型数组。
int (*p2)[5];  // p2行指针，用于指向数组长度为5的int型数组。

double (*p3)[5];  // p3是行指针，用于指向数组长度为5的double型数组。
一维数组名被解释为数组第0个元素的地址。
对一维数组名取地址得到的是数组的地址，是行地址。

2）二维数组名是行地址
int bh[2][3] = { {11,12,13},{21,22,23} };
bh是二维数组名，该数组有2两元素，每一个元素本身又是一个数组长度为3的整型数组。
bh被解释为数组长度为3的整型数组类型的行地址。
如果存放bh的值，要用数组长度为3的整型数组类型的行指针。
int (*p)[3]=bh;

int bh[4][2][3];
bh是三维数组名，该数组有4元素，每一个元素本身又是一个2行3列的二维数组。
bh被解释为2行3列的二维数组类型的二维地址。
如果存放bh的值，要用2行3列的二维数组类型的二维指针。
int (*p)[2][3]=bh;

3）把二维数组传递给函数
如果要把bh传给函数，函数的声明如下：
void func(int (*p)[3],int len);
void func(int p[][3],int len);





*/

void test69_1(int p[][3], int len)
{
    for (int ii = 0; ii < len; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
            cout << "p[" << ii << "][" << jj << "]=" << p[ii][jj] << "  ";

        cout << endl;
    }
}

void test69_main()
{
    int a[10] = {0};
    cout << "数组a的第0个元素的地址" << a << endl;
    cout << "数组a的地址" << &a << endl; // 和上面的一样

    cout << "数组a第0个元素的地址+1（a+1=)" << a + 1 << endl; // 比第0个地址+多了4

    cout << "数组a的地址+1（&a+1)" << &a + 1 << endl; // 比第0个地址+多了40

    int *p1 = a;       // 存放a的地址
    int(*p2)[10] = &a; // 存放a这一行的地址需要用行指针

    int bh[2][3] = {{11, 12, 13}, {21, 22, 23}};

    test69_1(bh, 2);
}

int main()
{

    // test62_main();
    // test63_main();
    // test64_main();
    // test65_main();
    test66_main();
}
