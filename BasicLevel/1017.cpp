#include <iostream>
using namespace std;
int main()
{
    //不超过 1000 位的正整数
    //模拟手动实现除法 54/6
    string s;
    int b;
    cin >> s >> b;
    int q = (s[0] - '0') / b;
    if (q != 0 || s.length() == 1)
        cout << q;
    int r = (s[0] - '0') % b;
    for (int i = 1; i < s.length(); i++)
    {
        //商
        // div = (mod * 10 + (A[i] - '0')) / B;
        //余数
        // mod = ((mod * 10 + A[i] - '0')) % B;
        q = (r * 10 + s[i] - '0') / b;
        cout << q;
        r = (r * 10 + s[i] - '0') % b;
    }
    cout << " " << r;
    return 0;
}