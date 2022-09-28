#include<iostream>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int diff=b-a;
    if(diff%100>=50){//四舍五入
        diff=diff/100+1;
    }else{
        diff=diff/100;
    }
    int h=diff/3600;
    int m=diff%3600/60;
    int s=diff%60;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}