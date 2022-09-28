#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int a,b,r;
    //D (1<D≤10)进制数
    cin >> a >> b >> r;
    int n=a+b;
    //n==0的情况不能忽略,否则会部分正确
    if(n==0){
        cout << 0;
        return 0;
    }
    //n进制转换为r进制
    stack<int> s;
    while(n){
        s.push(n%r);
        n/=r;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}