#include<iostream>
using namespace std;
int main()
{
    int n,cnt=0;
    int left=0,right=0,now=1,a=1;
    cin >> n;
    while(n/a){
        left=n/(a*10);
        now=n/a%10;
        right=n%a;
        if(now==0) cnt+=left*a;
        else if(now==1) cnt+=left*a+right+1;
        else cnt+=(left+1)*a;
        a*=10; 
    }
    cout << cnt;
    return 0;
}