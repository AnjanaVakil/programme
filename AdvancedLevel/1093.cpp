#include<iostream>
using namespace std;
//自己并没有独立写出来
const int MOD=1000000007;
int main()
{
    string s;
    cin >> s;
    int countP=0,countT=0,countPAT=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='T') countT++;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='T') countT--;
        if(s[i]=='P') countP++;
        if(s[i]=='A') countPAT=(countPAT+countP*countT)%MOD;
    }
    cout << countPAT;
    return 0;
}