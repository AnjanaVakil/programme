#include<iostream>
#include<cmath>
using namespace std;
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
        if(is_prime(n)==false){
            printf("No\n");
            continue;
        }
        int len=0,arr[100];
        //23 2 arr[]=11101  11 5 2 1 0
        //0*2+1=1 1*2+1=3 3*2+1=7 7*2+0=14 14*2+1=29 
        //10进制转d进制
        do{
            arr[len++]=n%d;
            n/=d;
        }while(n!=0);
        //d进制转10进制
        for(int i=0;i<len;i++){
            n=n*d+arr[i];
        }
        printf("%s",is_prime(n)?"Yes\n":"No\n");
    }
    return 0;
}