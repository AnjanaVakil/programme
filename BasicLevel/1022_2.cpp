#include<iostream>
using namespace std;
int main()
{
    int a,b,r;
    cin >> a >> b >> r;
    int n=a+b;
    if(n==0){
        cout << 0;
        return 0;
    }
    int s[100];
    int i=0;
    while(n!=0){
        s[i++]=n%r;
        n/=r;
    }
    for(int j=i-1;j>=0;j--){
        cout << s[j];
    }
    return 0;
}