#include <stdio.h>
int main()
{
    // int a, b, c, kase = 0, flag = 0;
    // scanf("%d %d %d",&a,&b,&c);
    // for (int i = 10; i <= 100; i++)
    // {
    //     if (i % 3 == a && i % 5 == b && i % 7 == c)
    //     {
    //         printf("Case %d:%d\n", ++kase, i);
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (!flag)
    //     printf("Case %d:No answer\n", ++kase);

    //可以不用flag标记,用for循环结束的条件标记是否找到
    int a, b, c, kase = 0, i;
    scanf("%d %d %d", &a, &b, &c);
    for (i = 10; i <= 100; i++)
    {
        if (i % 3 == a && i % 5 == b && i % 7 == c)
        {
            printf("Case %d:%d\n", ++kase, i);
            break;
        }
    }
    if (i == 101)
        printf("Case %d:No answer\n", ++kase);
    return 0;
}