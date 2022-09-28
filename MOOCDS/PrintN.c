#include<stdio.h>
void PrintN(int N);
int main()
{
    int N;
    scanf("%d",&N);
    PrintN(N);
    return 0;
}
//1000 000可以成功打印
void PrintN(int N)
{
    int i;
    for(i=1;i<=N;i++){
        printf("%d\n",i);
    }
    return;
}
//1000 000无法成功打印,段错误
// void PrintN(int N)
// {
//     if(N){
//         PrintN(N-1);
//         printf("%d\n",N);
//     }
//     return;
// }