#include<iostream>
using namespace std;
int main()
{
    //大神的思路
    //对于每一A,前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数
    string s;
    cin >> s;
    int res=0,countt=0,countp=0,len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='T') countt++;
    }
    for(int i=0;i<len;i++){
        if(s[i]=='P') countp++;
        if(s[i]=='T') countt--;
        if(s[i]=='A') res=(res+(countp*countt)%1000000007)%1000000007;
    }
    cout << res;
    return 0;
}