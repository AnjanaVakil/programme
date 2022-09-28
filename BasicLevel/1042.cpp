#include<iostream>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int str[256]={0};
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            str[s[i]]++;
        }
        if(s[i]>='A' && s[i]<='Z'){
            str[s[i]+32]++;
        }
    }
    int maxnum=0;
    char maxvalue;
    for(int i=0;i<256;i++){
        if(str[i]>maxnum){
            maxnum=str[i];
            maxvalue=i;
        }
    }
    cout << maxvalue << " " << maxnum;
    return 0;
}