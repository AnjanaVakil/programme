#include<iostream>
#include<cmath>
#include<string>
using namespace std;
bool is_prime(int n)
{
    if(n<=1) return false;
    //四舍五入避免了浮点误差
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int l,k;
    string s,t;
    cin >> l >> k >> s;
    // int flag=0;
    for(int i=0;i<=l-k;i++){
        t=s.substr(i,k);
        int num=stoi(t);
        if(is_prime(num)){
            cout << t;
            //return 0比加一个flag变量更加简洁
            return 0;
            // flag=1;
            // break;
        }
    }
    // if(!flag) cout << "404\n";
    cout << "404";
    return 0;
}