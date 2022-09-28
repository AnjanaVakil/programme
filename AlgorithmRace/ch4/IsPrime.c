//有问题
//n=1或者n太大时请勿调用
// int is_prime(int n)
// {
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0) return 0;
//     }
//     return 1;
// }
int is_prime(int n)
{
    if(n<=1) return 0;
    //四舍五入避免了浮点误差
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++){
        if(n%i==0) return 0;
    }
    return 1;
}