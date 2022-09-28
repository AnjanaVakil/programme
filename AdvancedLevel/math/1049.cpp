//14:00-04 22'运行超时
#include<iostream>
using namespace std;
int main()
{
    int n,cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s=to_string(i);
        for(int j=0;j<s.length();j++){
            if(s[j]=='1') cnt++;
        }
    }
    cout << cnt;
    return 0;
}