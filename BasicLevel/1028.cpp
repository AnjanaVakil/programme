#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct people
{
    char name[6];
    int year, month, day;
};
bool isRational(people a)
{
    if (a.year > 2014 || (a.year == 2014 && a.month > 9) || (a.year == 2014 && a.month == 9 && a.day > 6))
    {
        return false;
    }
    if ((2014 - a.year > 200) || (2014 - a.year == 200 && a.month < 9) || (2014 - a.year == 200 && a.month == 9 && a.day < 6))
    {
        return false;
    }
    return true;
}
bool cmp(people a, people b)
{
    // if (a.year != b.year)
    // {
    //     return a.year < b.year;
    // }
    // else
    // {
    //     if (a.month != b.month)
    //     {
    //         return a.month < b.month;
    //     }
    //     else
    //     {
    //         return a.day < b.day;
    //     }
    // }
    if (a.year != b.year)
    {
        return a.year < b.year;
    }
    else if (a.month != b.month)
    {
        return a.month < b.month;
    }
    else
    {
        return a.day < b.day;
    }
}
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    people peo[n];
    people p;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", p.name, &p.year, &p.month, &p.day);
        if (isRational(p))
        {
            peo[j++] = p;
        }
    }
    sort(peo, peo + j, cmp);
    //注意特殊情况
    //当有效生日个数为0时，不需要输出最年长和最年轻人的姓名，且0后面不能有空格。
    cout << j;
    if (j != 0)
    {
        cout << " " << peo[0].name << " " << peo[j - 1].name;
    }
    return 0;
}