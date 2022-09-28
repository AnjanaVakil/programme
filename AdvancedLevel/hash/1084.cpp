#include<iostream>
using namespace std;
//17:48-16:05 17min AC
int main()
{
    string s,t;
    cin >> s >> t;
    bool flag[256]={false};
    for(int i=0;i<t.length();i++){
        flag[toupper(t[i])]=true;
    }
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            s[i]=toupper(s[i]);
            if(flag[s[i]]==false){
                cout << s[i];
                flag[s[i]]=true;
            }
        }else if(flag[s[i]]==false){
            cout << s[i];
            flag[s[i]]=true;
        }
    }
    return 0;
}