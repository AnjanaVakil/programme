#include<iostream>
#include<cmath>
using namespace std;
//n由 10进制转d进制 1<d<=10
//转换到的数组是从高位到低位，故转换为10进制时
//只要从低位开始加 即可得到反转的d进制对应的10进制
int TentoD_rev(int n,int d)
{
    int len=0,arr[100];
    do{
        arr[len++]=n%d;
        n/=d;
    }while(n!=0);
    int result=0;
    for(int i=0;i<len;i++) result=result*d+arr[i];
    return result;
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
    // freopen("input.txt","r",stdin); 
    while(cin >> n >> d){
        if(n<0) break;
        int reverse=TentoD_rev(n,d);
        // cout << reverse << endl;
        if(is_prime(n) && is_prime(reverse)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}