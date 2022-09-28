#include <stdio.h>
int main()
{
    int a, b, da, db;
    scanf("%d %d %d %d", &a, &da, &b, &db);
    int res1 = 0;
    while (a != 0)
    {
        if (a % 10 == da)
        {
            res1 *= 10;
            res1 += da;
        }
        a /= 10;
    }
    int res2 = 0;
    while (b != 0)
    {
        if (b % 10 == db)
        {
            res2 *= 10;
            res2 += db;
        }
        b /= 10;
    }
    printf("%d", res1 + res2);
}