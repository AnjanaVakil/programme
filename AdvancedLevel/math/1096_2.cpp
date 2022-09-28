#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int first=0,len=0;
    int sqr=(int)sqrt(n*1.0);
    for(int i=2;i<=sqr;i++){
        int j;
        long long temp=1;
        for(j=i;j<=sqr;j++){
            temp*=j;
            if(n%temp!=0) break;
        }
        if(j-i>len){
            len=j-i;
            first=i;
        }
    }
    if(first==0){
        cout << 1 << "\n" << n;
    }else{
        cout << len << "\n";
        for(int i=0;i<len;i++){
            cout << first+i;
            if(i!=len-1) cout << "*";
        }
    }
    return 0;
}