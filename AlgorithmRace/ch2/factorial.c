#include<stdio.h>
#include<time.h>
int main()
{
    // int n,S=0;
    // scanf("%d",&n);
    // for(int i=1;i<=n;i++){
    //     int factorial=1;
    //     for(int j=1;j<=i;j++)
    //         factorial*=j;
    //     S+=factorial;
    // }
    // printf("%d\n",S%1000000);
    //100 乘法溢出
    //-961703

    const int MOD=1000000;
    int n,S=0;
    scanf("%d",&n);
    if(n>25) n=25;
    for(int i=1;i<=n;i++){
        int factorial=1;
        for(int j=1;j<=i;j++)
            factorial=(factorial*j%MOD);
        S=(S+factorial)%MOD;
    }
    printf("%d\n",S);
    printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}