#include<iostream>
#include<cmath>
using namespace std;
//12' 只有题目给的测试样例通过了
//题目完全理解错误
//首先判断N,若N不是素数直接输出No，否则将其转换为D进制，然后逆序，再将逆序后的D进制数转换为十进制数q，判断q是否为素数即可。
//d进制转10进制 1<d<=10
int res(int n,int d)
{
int i=0,ans=0;
    while(n){
        ans+=(n%10*pow(d,i++));
        n/=10;
    }
    return ans;
}
int reverse(int n)
{
    int ans=0,i=0;
    while(n){
        ans=ans*(i++)*10;
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
//判断prime
bool is_prime(int n)
{
    if(n<=1) return false;
    // int num=floor(sqrt(n)+0.5);
    //另一种写法
    int num=int(sqrt(n*1.0));
    for(int i=2;i<=num;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,d;
    freopen("input.txt","r",stdin); 
    while(cin >> n >> d){
        if(n<0) break;
        int a=res(n,d),b=reverse(a);
        // cout << b << endl;
        if(is_prime(n) && is_prime(b)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}