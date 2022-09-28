#include <stdio.h>
void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b, c, m, n, l, x, y, z;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &m, &n, &l);
    if (a > m || (a == m && b > n) || (a == m && b == n && c > l))
    {
        my_swap(&a, &m);
        my_swap(&b, &n);
        my_swap(&c, &l);
        printf("-");
    }
    z = l < c ? l - c + 29 : l - c;
    n = l < c ? n - 1 : n;
    y = n < b ? n - b + 17 : n - b;
    x = n < b ? m - a - 1 : m - a;
    printf("%d.%d.%d", x, y, z);
    return 0;
}