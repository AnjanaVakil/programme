#include<iostream>
using namespace std;
// 16:15-22 7min AC
int main()
{
    string s,t;
    cin >> s >> t;
    int flag[256]={0};
    for(int i=0;i<s.length();i++){
        flag[s[i]]++;
    }
    int less=0;
    for(int i=0;i<t.length();i++){
        flag[t[i]]--;
        if(flag[t[i]]<0){
            less++;
        }
    }
    if(less!=0){
        cout << "No " << less;
    }else{
        cout << "Yes " << s.length()-t.length();
    }
    return 0;
}