#include<stdio.h>
void swap_wrong(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}
void swap_right(int* a,int* b)
{
    int t=*a;
    *a=*b;  
    *b=t;
}
int main()
{
    int a=3,b=4;
    swap_wrong(3,4);
    // swap_right(&a,&b);
    printf("%d %d",a,b);
    return 0;
}