#include<stdio.h>
int main()
{
    // int n,count=0;
    // scanf("%d",&n);
    // while(n>1){
    //     if(n%2==1) n=3*n+1;
    //     else n/=2;
    //     printf("%d\n",n);
    //     count++;
    // }
    // printf("%d",count);
    //987654321
    //-1332004332
    //1

    int n2,count=0;
    scanf("%d",&n2);
    long long n=n2;
    while(n>1){
        if(n%2==1) n=3*n+1;
        else n/=2;
        printf("%lld\n",n);
        count++;
    }
    printf("%d",count);
    return 0;
}