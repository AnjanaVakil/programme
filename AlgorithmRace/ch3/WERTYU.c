#include<stdio.h>
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    int c,i;
    while((c=getchar())!=EOF){
        for(i=0;s[i] && s[i]!=c;i++);
        if(s[i]) putchar(s[i-1]);
        else putchar(c);
    }
    //O S,GOMR YPFSU/
    return 0;
}