#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
//使用常量数组
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
char r(char ch)
{
    if(isalpha(ch)) return rev[ch-'A'];
    else return rev[ch-'0'+25];
}
int main()
{
    char s[30];
    while(scanf("%s",s)==1){
        int len=strlen(s);
        int p=1,m=1;
        for(int i=0;i<(len+1)/2;i++){
            if(s[i]!=s[len-i-1]) p=0;
            if(r(s[i])!=s[len-i-1]) m=0;
        }
        printf("%s -- is ",s);
        if(p && m){
            printf("%s.\n\n",msg[3]);
        }else if(p){
            printf("%s.\n\n",msg[1]);
        }else if(m){
            printf("%s.\n\n",msg[2]);
        }else{
            printf("%s.\n\n",msg[0]);
        }
    }
}
/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
*/