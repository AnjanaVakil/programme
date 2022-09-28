#include<iostream>
#include<algorithm>
using namespace std;
bool is_palindromic(int n)
{
    string s=to_string(n);
    string t=to_string(n);
    reverse(s.begin(),s.end());
    return s==t;
}
int main()
{
    //提交只有16分
    //一个不超过1000位的正整数。所以要使用大数加法
    int n,t;
    cin >> n;
    string s;
    int i=0;
    while(!is_palindromic(n) && (i++)<10){
        s=to_string(n);
        reverse(s.begin(),s.end());
        //stoi前置0会被舍去
        t=stoi(s);
        cout << n << " + " << t << " = " << n+t << endl;
        n=n+t;
    }
    if(i<10) cout << n << " is a palindromic number.\n";
    else cout << "Not found in 10 iterations.\n";
    return 0;
}