#include<iostream>
using namespace std;
int main()
{
    // N 位的进制表（0 < N ≤ 20）
    //先将要相加的两个字符串S1和S2都扩展到和S等长，
    //然后从后往前按照进制相加到ans中，注意进位carry，
    //最后输出字符串ans，记得不要输出字符串ans前面的0。
    //如果一次都没有输出，最后要输出一个0～
    string s,a,b,ans;
    cin >> s >> a >> b;
    ans=s;
    string sa(s.length()-a.length(),'0');
    a=sa+a;
    string sb(s.length()-b.length(),'0');
    b=sb+b;
    int carry=0;
    for(int i=s.length()-1;i>=0;i--){
        int mod=(s[i]=='0')?10:(s[i]-'0');
        ans[i]=(a[i]-'0'+b[i]-'0'+carry)%mod+'0';
        carry=(a[i]-'0'+b[i]-'0'+carry)/mod;
    }
    if(carry!=0) ans='1'+ans;
    int flag=0;
    for(int i=0;i<ans.length();i++){
        if(ans[i]!='0' || flag==1){
            flag=1;
            cout << ans[i];
        }
    }
    // 如果一次都没有输出，最后要输出一个0～
    if(flag==0) cout << 0;
    return 0;
}