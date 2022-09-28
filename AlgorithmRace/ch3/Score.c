#include<stdio.h>
#include<string.h>
#define maxn 80+5
int main()
{
    char s[maxn];
    scanf("%s",s);
    int temp=0,res=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='O'){
            temp++;
            res+=temp;
        }
        if(s[i]=='X'){
            temp=0;
        }
    }
    printf("%d\n",res);
    return 0;
    //OOXXOXXOOO
}