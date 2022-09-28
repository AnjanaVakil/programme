#include<iostream>
using namespace std;
int main()
{
    //给三个十进制的数，把它们转换为十三进制的数输出
    char c[14]={"0123456789ABC"};
    printf("#");
    for(int i=0;i<3;i++){
        int num;
        scanf("%d",&num);
        printf("%c%c",c[num/13],c[num%13]);
    }
    return 0;
}