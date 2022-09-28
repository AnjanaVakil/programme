#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%.*lf\n",c,(double)a/b);
    return 0;
}