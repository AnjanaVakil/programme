#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int a[123] = {0}, b[123] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        a[(int)s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        b[(int)t[i]]++;
    }
    int diff1 = 0, diff2 = 0, flag = 0;
    for (int i = 0; i < 123; i++)
    {
        if (a[i] >= b[i])
        {
            diff1 += (a[i] - b[i]);
        }
        else if (b[i] != 0 && a[i] < b[i])
        {
            diff2 += (b[i] - a[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Yes ";
        cout << diff1;
    }
    else
    {
        cout << "No ";
        cout << diff2;
    }
    return 0;
}