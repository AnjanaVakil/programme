#include <stdio.h>
#include <string.h>
int main()
{
    char a[10],b[10];
    int da, db;
    scanf("%s %d %s %d", a, &da, b, &db);
    int res1 = 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]-'0'==da){
            res1=res1*10+da;
        }
    }
    int res2 = 0;
    for(int i=0;i<strlen(b);i++){
        if(b[i]-'0'==db){
            res2=res2*10+db;
        }
    }
    printf("%d", res1 + res2);
}