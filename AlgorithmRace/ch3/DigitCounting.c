#include<stdio.h>
#include<string.h>
#define maxn 10005
char s[maxn];
int main()
{
    int ans[15];
    scanf("%s",s);
    memset(ans,0,sizeof(ans));
    for(int i=0;i<strlen(s);i++){
        ans[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        printf("%d ",ans[i]);
    }
    return 0;
    //12345678901112
}