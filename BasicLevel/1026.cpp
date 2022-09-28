#include<iostream>
using namespace std;
int main()
{
    int c1,c2;
    scanf("%d %d",&c1,&c2);
    //题目要求不足1秒的时间四舍五入到秒
    //所以先给(b-a)加上50
    //这样如果(b-a)/100的小数位大于等于0.5则会进位，小于等于0.5则会舍去
    int diff=((c2-c1)+50)/100;
    int h=diff/3600;
    int m=(diff-h*60*60)/60;
    int s=(diff-h*60*60-m*60);
    // diff%=3600;
    // int m=diff/60;
    // int s=diff%60;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}