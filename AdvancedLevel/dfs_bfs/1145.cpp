#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100010;
int pos[maxn];
bool isPrime(int n)
{
    if(n<=1) return false;
    int sqr=(int)sqrt(n*1.0);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false; 
    }
    return true;
}
int main()
{
    int tsize,n,m;
    cin >> tsize >> n >> m;
    while(!isPrime(tsize)){
        tsize++;
    }
    int input;
    for(int i=0;i<n;i++){
        cin >> input;
        //with positive increments only
        //所以平方探测法的k 是 0-tsize-1 的范围
        int j;
        for(j=0;j<tsize;j++){
            int index=(input+j*j)%tsize;
            if(pos[index]==0){
                pos[index]=input;
                break;
            }
        }
        if(j==tsize){
            printf("%d cannot be inserted.\n",input);
        }
    }
    double ASL=0.0;
    int key;
    for(int i=0;i<m;i++){
        cin >> key;
        int j;
        for(j=0;j<=tsize;j++){
            ASL++;
            int index=(key+j*j)%tsize;
            if(pos[index]==key || pos[index]==0){
                break;
            }
        }
    }
    printf("%.1lf\n",ASL/m*1.0);
    return 0;
}