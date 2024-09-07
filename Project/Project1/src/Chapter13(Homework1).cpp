#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*课后作业 - 第二题
在界面上输入数字的月份（1-12），输出对应月份的英文单词的全称，
如果输入的数字不合法，给出提示。
其它要求：
1）用if … else if …实现；
2）用switch实现；
3）用字符串数组（C风格和C++风格）实现。
*/

// 用 if..else if 实现
void test02_func1(int month)
{
    if (month == 1)
    {
        cout << "Jan" << endl;
    }
    else if (month == 2)
    {
        cout << "Feb" << endl;
    }
    else if (month == 3)
        cout << "March\n";
    else if (month == 4)
        cout << "April\n";
    else if (month == 5)
        cout << "May\n";
    else if (month == 6)
        cout << "June\n";
    else if (month == 7)
        cout << "July\n";
    else if (month == 8)
        cout << "August\n";
    else if (month == 9)
        cout << "September\n";
    else if (month == 10)
        cout << "October\n";
    else if (month == 11)
        cout << "November\n";
    else if (month == 12)
        cout << "December\n";
    else
        cout << "输入的数字不正确。\n";
}

// 用switch实现；实现
void test02_func2(int month)
{
    switch (month)
    {
    case 1:
        cout << "January\n";
        break;
    case 2:
        cout << "February\n";
        break;
    case 3:
        cout << "March\n";
        break;
    case 4:
        cout << "April\n";
        break;
    case 5:
        cout << "May\n";
        break;
    case 6:
        cout << "June\n";
        break;
    case 7:
        cout << "July\n";
        break;
    case 8:
        cout << "August\n";
        break;
    case 9:
        cout << "September\n";
        break;
    case 10:
        cout << "October\n";
        break;
    case 11:
        cout << "November\n";
        break;
    case 12:
        cout << "December\n";
        break;
    default:
        cout << "输入的数字不正确。\n";
    }
}

// 用字符串数组（c,c++) 实现
void test02_func3(int month)
{
    char montharr[12][10] = // 12个月，最长的是9月，有10个字符
        {"January",
         "February",
         "March",
         "April",
         "May",
         "June",
         "July",
         "August",
         "September",
         "October",
         "November",
         "December"};

    // c++风格
    string montharr_cpp[12] =
        {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
        };
    if (month >= 1 && month <= 12)
        cout << montharr_cpp[month - 1] << endl;
}
void test02_translate(const int &month, void (*pf)(int))
{
    pf(month);
}

void test02_main()
{
    int month = 0;
    cout << "请输入月份 1-12" << endl;
    cin >> month;

    test02_translate(month, test02_func3); // 用回调函数实现
}

/*课后作业 - 三、循环计数
有两个任务：
1）采用一个while循环，把1到100之间的数值累加起来。
2）采用一个for循环，把用户每次从键盘输入的数值累加起来，如果总和超过了5000，循环结束。


*/

void test03_main()
{
    int i = 1;
    int sum = 0;
    while (i < 101)
    {
        sum = sum + i;
        i++;
    }
    cout << sum << endl;
    int sum2 = 0;
    for (sum2 = 0; sum2 <= 5000;)
    {
        int val = 0;
        cout << "请输入一个数字：";
        cin >> val;
        sum = sum + val;
    }
}

/*四、循环选数
有两个任务：
1）用一个while循环，接受从键盘输入的整数，如果输入的整数不在1到100之间（包括1和100），认为无效，
丢弃；如果输入的整数在1到100之间，则把每次输入的值累加起来；
如果输入的整数为0，跳出循环。最后，显示有效数据的个数和总和。
2）输出1到100之间（包括1和100）的能整除5的数字。



*/
void test04_main()
{
    int val;
    int ii = 0;
    int sum = 0;

    while (true)
    {
        cout << "请输入一个整数：";
        cin >> val;
        if (val == 0)
            break;
        else if (val < 1 || val > 100)
            continue;
        else
        {
            // 整数在1到100之间的有效数据。
            ii++;
            sum += val;
        }
    }
    cout << "有效数据的个数=" << ii << "，有效数据的总和=" << sum << endl;
}

/*五、玩转字符*/

/*六、计算字符串的长度*/
/*七 、显示字符串中的字符*/
/*八、字符串反转*/
/*九、二维数组的应用*/
/*十、把整数转换成字符串*/
/*十一、把字符串转换成整数*/
/*十二、实现strcpy()和strncpy()函数*/

int main()
{
    // test02_main();
    // test03_main();
    test04_main();
    return 0;
}