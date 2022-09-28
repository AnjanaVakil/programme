#include<iostream>
using namespace std;
int main()
{
    int a,b,r;
    cin >> a >> b >> r;
    int sum=a+b;
    int res[31],num=0;
    do{
        res[num++]=sum%r;
        sum/=r;
    }while(sum!=0);
    for(int i=num-1;i>=0;i--){
        cout << res[i];
    }
    return 0;
}