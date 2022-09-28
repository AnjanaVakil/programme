#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    string id;
    int d;
    int c;
};
bool sum_cmp(student stu1, student stu2)
{
    if (stu1.d + stu1.c != stu2.d + stu2.c)
    {
        return stu1.d + stu1.c > stu2.d + stu2.c;
    }
    else if (stu1.d + stu1.c == stu2.d + stu2.c)
    {
        if (stu1.d == stu2.d)
        {
            return stu1.id < stu2.id;
        }
        return stu1.d > stu2.d;
    }
}
int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    int m = 0;
    vector<student> stu1, stu2, stu3, stu4;
    student stu;
    string id;
    int d, c;
    for (int i = 0; i < N; i++)
    {
        cin >> id >> d >> c;

        if (d >= L && c >= L)
        { //如果达到最低分数线
            if (d >= H && c >= H)
            {
                stu.id = id;
                stu.d = d;
                stu.c = c;
                stu1.push_back(stu);
                m += 1;
            }
            else if (d >= H && c < H)
            {
                stu.id = id;
                stu.d = d;
                stu.c = c;
                stu2.push_back(stu);
                m += 1;
            }
            else if (d < H && c < H && d >= c)
            {
                stu.id = id;
                stu.d = d;
                stu.c = c;
                stu3.push_back(stu);
                m += 1;
            }
            else
            {
                stu.id = id;
                stu.d = d;
                stu.c = c;
                stu4.push_back(stu);
                m += 1;
            }
        }
    }
    cout << m << endl;
    sort(stu1.begin(), stu1.end(), sum_cmp);
    for (int i = 0; i < stu1.size(); i++)
    {
        cout << stu1[i].id << " " << stu1[i].d << " " << stu1[i].c << endl;
    }
    sort(stu2.begin(), stu2.end(), sum_cmp);
    for (int i = 0; i < stu2.size(); i++)
    {
        cout << stu2[i].id << " " << stu2[i].d << " " << stu2[i].c << endl;
    }
    sort(stu3.begin(), stu3.end(), sum_cmp);
    for (int i = 0; i < stu3.size(); i++)
    {
        cout << stu3[i].id << " " << stu3[i].d << " " << stu3[i].c << endl;
    }
    sort(stu4.begin(), stu4.end(), sum_cmp);
    for (int i = 0; i < stu4.size(); i++)
    {
        cout << stu4[i].id << " " << stu4[i].d << " " << stu4[i].c << endl;
    }
    return 0;
}