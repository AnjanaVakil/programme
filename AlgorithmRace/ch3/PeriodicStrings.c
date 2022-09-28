#include<stdio.h>
#include<string.h>
#define maxn 80+5
int main()
{
    char s[maxn];
    scanf("%s",s);
    int period=1,flag=0;
    for(int i=0;i<strlen(s);i++){
        for(int j=i+1;j<strlen(s);j+=period){
            if(s[i]==s[j]){
                period=j-i;
            }
        }
    }
    printf("%d\n",period);
    return 0;
}