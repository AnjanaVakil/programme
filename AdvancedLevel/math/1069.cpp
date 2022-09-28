#include<iostream>
#include<algorithm>
using namespace std;
//12:25-40 14' 会有超时问题
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    string s;
    cin >> s;
    while(1){
        sort(s.begin(),s.end(),cmp);
        int a=stoi(s);
        sort(s.begin(),s.end());
        int b=stoi(s);
        int res=a-b;
        printf("%04d - %04d = %04d\n",a,b,res); 
        if(res==0 || res==6174) break;
        s=to_string(res);
    };
    return 0;
}