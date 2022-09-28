#include<stdio.h>
//整数不超过100个
//数组一般会声明得稍大一些
// #define maxn 105
#define maxn 100000000
//比较大的函数应尽量声明在main函数外
int a[maxn];
int main()
{
    int x,n=0;
    //数组声明放在main函数内,数组稍大就会异常退出
    //chengjing@AnjanaMacBook-Pro ch3 % ./a.out       
    //zsh: segmentation fault  ./a.out
    //int a[maxn];
    while(scanf("%d",&x)==1){
        a[n++]=x;
    }
    for(int i=n-1;i>=1;i--){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[0]);
    return 0;
}