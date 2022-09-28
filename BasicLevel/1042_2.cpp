#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int a[26]={0};
    for(int i=0;i<s.length();i++){
        //用tolower转为小写
        s[i]=tolower(s[i]);
    }
    for(int i=0;i<s.length();i++){
        //用islower判断每一个字符是否是字母
        if(islower(s[i])){
            a[s[i]-'a']++;
        }
    }
    int max=a[0],t=0;
    for(int i=0;i<26;i++){
        if(a[i]>max){
            max=a[i];
            t=i;
        }
    }
    printf("%c %d",t+'a',max);
    //输出e 7
    // cout << t+'a' << " " << max;
    //输出101 7
}