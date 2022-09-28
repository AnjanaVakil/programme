#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 100+5
int main()
{
    //C6H5OH
    double ans[]={12.01,1.008,16.00,14.01};
    char s[maxn];
    scanf("%s",s);
    double res=0.0;
    for(int i=0;i<strlen(s);i++){
        int cnt=1;
        if(s[i]=='C'){
            if(isdigit(s[i+1])){
                cnt=(s[i+1]-'0');
            }
            res=(res+cnt*ans[0]);
        }
        if(s[i]=='H'){
            if(isdigit(s[i+1])){
                cnt=(s[i+1]-'0');
            }
            res=(res+cnt*ans[1]);
        }
        if(s[i]=='O'){
            if(isdigit(s[i+1])){
                cnt=(s[i+1]-'0');
            }
            res=(res+cnt*ans[2]);
        }
        if(s[i]=='N'){
            if(isdigit(s[i+1])){
                cnt=(s[i+1]-'0');
            }
            res=(res+cnt*ans[3]);
        }
    }
    printf("%.3lf\n",res);
    return 0;
}