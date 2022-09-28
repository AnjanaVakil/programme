#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    char s[20],buf[99];
    //s前面没&符号 scanf("%s",s); scanf("%d",&n);
    scanf("%s",s);
    for(int abc=111;abc<=999;abc++){
        for(int de=11;de<=99;de++){
            int x=abc*(de%10),y=abc*(de/10),z=abc*de;
            //sprintf输出到字符串,printf输出到文件,printf输出到屏幕
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int ok=1;
            for(int i=0;i<strlen(buf);i++){
                //strchr在一个字符串中查找单个字符
                if(strchr(s,buf[i])==NULL) ok=0;
            }
            if(ok){
                printf("<%d>\n",++count);
                printf("%5d\n",abc);
                printf("X%4d\n",de);
                printf("-----\n");
                printf("%5d\n",x);
                printf("%4d\n",y);
                printf("-----\n");
                printf("%5d\n\n",z);
            }
        }
    }
    printf("The numver of solutions=%d",count);
    return 0;
}