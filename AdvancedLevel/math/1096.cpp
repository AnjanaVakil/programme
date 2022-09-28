//07- 自己没思路
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max,maxnum;
    int sqr=(int)sqrt(n*1.0);
    for(int i=2;i<sqr;i++){
        int maxnum=0;
        int temp=n;
        int factor=i;
        while(temp%factor==0){
            temp/=i;
            maxnum++;
        }
    }
    return 0;
}