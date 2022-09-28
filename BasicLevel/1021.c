#include <stdio.h>
#include <string.h>
int main()
{
    int res[10]={0};
    char n[1000];
    scanf("%s", n);
    for (int i = 0; i < strlen(n); i++)
    {
        res[n[i]-'0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (res[i] > 0)
        {
            printf("%d:%d\n", i, res[i]);
        }
    }
}