#include <iostream>
using namespace std;
int main()
{
    //    1 2 3 4 5 6 7
    //3 6 8 7 8 1 9 7 1
    string a, b, res;
    cin >> a >> b;
    //题目中是b的长度>a的长度,也有可能是a的长度>b的长度
    // int len = b.length() - a.length();
    // for (int i = a.length() - 1; i >= 0; i--)
    // {
    //     a[i + len] = a[i];
    // }
    // for (int i = 0; i < len; i++)
    // {
    //     a[i] = '0';
    // }
    //因为是字符串,要加'0'的话可以直接拼接
    int lena=a.length(),lenb=b.length();
    if(lena<lenb){
        for(int i=0;i<lenb-lena;i++){
            a='0'+a;
        }
    }else{
        for(int i=0;i<lena-lenb;i++){
            b='0'+b;
        }
    }
    int j = b.length();
    string str = "0123456789JQK";
    int temp;
    for (int i = 0; i < b.length(); i++)
    {
        if (j % 2)
        {
            temp = ((a[i] - '0') + (b[i] - '0')) % 13;
            cout << str[temp];
        }
        else
        {
            temp = ((b[i] - '0') - (a[i] - '0'));
            if (temp < 0)
            {
                temp += 10;
            }
            cout << str[temp];
        }
        j--;
    }
    return 0;
}