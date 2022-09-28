#include<iostream>
using namespace std;
int main()
{
    string s;
    //helloworld! 11
    cin >> s;
    int len=s.length();
    int n=len+2;
    int n1=n/3;
    //这两种计算n2的方法都行
    // int n2=n-n1*2;
    int n2=n/3+n%3;
    for(int i=0;i<n1-1;i++){
        cout << s[i];
        for(int j=0;j<n2-2;j++){
            cout << " ";
        }
        cout << s[len-i-1];
        cout << "\n";
    }
    for(int i=n1-1;i<n1+n2-1;i++){
        cout << s[i];
    }
    return 0;
}