#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
//部分正确 只通过了部分测试点
int main()
{
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < 4; i++)
    {
        v.push_back(s[i] - '0');
    }
    int result;
    do
    {
        sort(v.begin(), v.end(), cmp);
        int a = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
        sort(v.begin(), v.end());
        int b = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
        result = a - b;
        printf("%04d - %04d = %04d\n", a, b, result);
        s = to_string(result);
        v.clear();
        for (int i = 0; i < 4; i++)
        {
            v.push_back(s[i] - '0');
        }
    } while (result != 6174 && result != 0000);
    return 0;
}