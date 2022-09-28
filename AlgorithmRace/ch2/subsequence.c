#include <stdio.h>
int main()
{
    int n, m, kase = 0;
    scanf("%d%d", &n, &m);
    if(n>m){
        int temp=n;
        n=m;
        m=temp;
    }
    double res = 0;
    for (int i = n; i <= m; i++)
    {
        //自己是这样写的res=res+(1.0/i*i);
        //实际上,为了溢出错误,应该改为除法
        res = res + (1.0 / i / i);
    }
    printf("Case %d:%.5lf", ++kase, res);

    return 0;
}