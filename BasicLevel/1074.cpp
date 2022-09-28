#include<iostream>
#include<algorithm>
using namespace std;
/*
输入：
30527
29416
00001
输出：
100000
*/
int main()
{
    // N 位的进制表（0 < N ≤ 20）
    string s,a,b;
    cin >> s >> a >> b;
    string sa(s.length()-a.length(),'0');
    a=sa+a;
    string sb(s.length()-b.length(),'0');
    b=sb+b;
    string res;
    int carry=0;
    for(int i=s.length()-1;i>=0;i--){
        int mod=s[i]-'0';
        if(mod==0) mod=10;
        res+=((a[i]-'0'+b[i]-'0'+carry)%mod+'0');
        carry=(a[i]-'0'+b[i]-'0'+carry)/mod;
    }
    if(carry!=0) res='1'+res;
    cout << res << endl;
    //自己写的代码使用了string res+=,然后reverse后输出
    //当测试用例为下列时，错误：
    /*
    30527
    29416
    00001
    100000
    1%
    */
    /*
    30527
    06203
    415
    10270
    7201% 
    */
    //代码得分只有16分，所以不应该使用res+=
    //而是使用大佬的写法string res=s; res[i]=
    reverse(res.begin(),res.end());
    int flag=0;
    for(int i=0;i<res.length();i++){
        if(res[i]!='0' || flag==1){
            flag=1;
            cout << res[i];
        }
    }
    // 如果一次都没有输出，最后要输出一个0～
    if(flag==0) cout << 0;
    return 0;
}