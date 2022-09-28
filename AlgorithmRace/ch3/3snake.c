#include <stdio.h>
#include <string.h>
#define maxn 10
int a[maxn][maxn];
int main()
{
    int n;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int temp = 1, x = 0, y = n - 1;
    a[0][n - 1] = 1;
    while (temp < n * n)
    {
        //预判(是否出界或者是否已经是填过的格子)
        while (x + 1 < n && !a[x + 1][y]) //!a[x+1][y]即a[x+1][y]==0
            a[++x][y] = (++temp);
        while (y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = (++temp);
        while (x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = (++temp);
        while (y + 1 < n && !a[x][y + 1])
            a[x][++y] = (++temp);
        // for (int i = 1; i <= n; i++)
        // {
        //     a[i][n] = (temp++);
        // }
        // for (int i = n - 1; i >= 1; i--)
        // {
        //     a[n][i] = (temp++);
        // }
        // for (int i = n - 1; i >= 1; i--)
        // {
        //     a[i][1] = (temp++);
        // }
        // for (int i = 2; i <= n - 1; i++)
        // {
        //     a[1][i] = (temp++);
        // }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}