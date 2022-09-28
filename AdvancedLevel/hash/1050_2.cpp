#include<iostream>
#include<cstring>
using namespace std;
//They are students. aeiou
//Thy r stdnts.
//Hash
//The string lengths of both strings are no more than 10^4
//数组大小开为10000，就会有答案错误
char s[100000],t[100000];
int main()
{
    cin.getline(s,100000);
    cin.getline(t,100000);
    //使用int lens1 = strlen(s1);int lens2 = strlen(s2);的形式
    //否则直接放在for循环里面会超时～
    int lens=strlen(s),lent=strlen(t);
    bool flag[256]={false};
    for(int i=0;i<lent;i++){
        flag[t[i]]=true;
    }
    for(int i=0;i<lens;i++){
        if(flag[s[i]]==false){
            printf("%c",s[i]);
        }
    }
    return 0;
}