//31- 第一次做这种题，基本是靠提示写的
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if(n<=1) return false;
    //注意：循环外定义变量存储sqrt(n)
    int sqr=(int)sqrt(n*1.0);
    for(int i=2;i<sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}
const int maxn=100010;
int prime[maxn],pNum=0;//pNum为素数个数
bool p[maxn]={false}; 
//素数表
void findPrime()
{
    //注意：这里不能写成i<=maxn
    for(int i=2;i<maxn;i++){
        if(p[i]==false){
            prime[pNum++]=i;
        }
        for(int j=i+i;j<maxn;j+=i){
            p[j]=true;
        }
    }
}
// void findPrime()
// {
//     for(int i=1;i<maxn;i++){
//         if(isPrime(i)){
//             prime[pNum++]=i;
//         }
//     }
// }
struct factor{
    int x,cnt;
}fac[10];
int main()
{
    findPrime();
    int n;
    cin >> n;
    if(n==1){
        cout << "1=1";
        return 0;
    }
    cout << n << "=";
    int num=0;
    int sqr=(int)sqrt(n*1.0);
    for(int i=0;i<pNum && prime[i]<=sqr;i++){
        if(n%prime[i]==0){
            fac[num].x=prime[i];
            fac[num].cnt=0;
            while(n%prime[i]==0){
                fac[num].cnt++;
                n/=prime[i];
            }
            num++;
        }
        if(n==1) break;
    }
    if(n!=1){
        fac[num].x=n;
        fac[num++].cnt=1;
    }
    for(int i=0;i<num;i++){
        cout << fac[i].x;
        if(fac[i].cnt>1){
            cout << "^" << fac[i].cnt;
        }
        if(i!=num-1) cout << "*";
    }
    return 0;
}