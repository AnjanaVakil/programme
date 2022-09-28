#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    string s=to_string(a+b);
    int len=s.length();
    for(int i=0;i<len;i++){
        cout << s[i];
        if(s[i]=='-'){
            continue;
        }
        //只要当前位的下标i满足(i + 1) % 3 == len % 3并且i不是最后一位，
        //就在逐位输出的时候在该位输出后的后面加上一个逗号～
        if((i+1)%3==len%3 && i!=len-1) cout << ',';
    }
    return 0;   
}