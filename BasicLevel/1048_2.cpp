#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //    1 2 3 4 5 6 7
    //3 6 8 7 8 1 9 7 1
    string a, b, res;
    cin >> a >> b;
    int lena = a.length(), lenb = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (lena > lenb)
    {
        b.append(lena - lenb, '0');
    }
    else
    {
        a.append(lenb - lena, '0');
    }
    char str[14] = "0123456789JQK";
    int temp;
    for (int i = 0; i < a.length(); i++)
    {
        if (i % 2 == 0)
        {
            temp = (a[i] - '0' + b[i] - '0') % 13;
            res += str[temp];
        }
        else
        {
            temp = (b[i] - a[i]);
            if (temp < 0)
            {
                temp += 10;
            }
            res += str[temp];
        }
    }
    for (int i = res.length() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    return 0;
}