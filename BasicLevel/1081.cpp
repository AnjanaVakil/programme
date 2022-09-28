#include <iostream>
using namespace std;
string res(string s)
{
    int aflag = 0, nflag = 0;
    if (s.length() < 6)
    {
        return "Your password is tai duan le.\n";
    }
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]) || isalpha(s[i]) || s[i]=='.') continue;
        else break;
    }
    if (i < s.length())
    {
        return "Your password is tai luan le.\n";
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            aflag = 1;
        }
        if (isalpha(s[i]))
        {
            nflag = 1;
        }
    }
    if (aflag == 0)
    {
        return "Your password needs shu zi.\n";
    }
    if (nflag == 0)
    {
        return "Your password needs zi mu.\n";
    }
    if (aflag && nflag)
    {
        return "Your password is wan mei.\n";
    }
}
int main()
{
    int n;
    cin >> n;
    //非空字符串，每个字符串以回车结束，
    //但是字符串里面可能会有空格，
    //所以不能直接用cin，要用getline接收一行字符。
    //在接收完n后要getchar()读取一下换行符才能用getline，否则换行符会被读进getline中～
    getchar();
    string s;
    for (int i = 0; i < n; i++)
    {
        //非法的字符串有空白，所以cin接收会出问题
        getline(cin,s);
        cout << res(s);
    }
    return 0;
}