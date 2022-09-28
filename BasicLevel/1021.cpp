#include<iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int res[10]={0};
    for(int i=0;i<s.length();i++){
        res[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(res[i]!=0){
            cout << i << ":" << res[i] << endl;
        }
    }
}