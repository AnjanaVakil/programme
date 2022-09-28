#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();//读取换行符，否则字符串读取错误
    string s,res;
    for(int i=0;i<n;i++){
        getline(cin,s);
        reverse(s.begin(),s.end());
        int sLen=s.length();
        if(i==0){
            res=s;
        }else{
            int resLen=res.length();
            if(sLen<resLen) swap(res,s);
            int minLen=min(sLen,resLen);
            for(int j=0;j<minLen;j++){
                if(res[j]!=s[j]){
                    res=res.substr(0,j);
                    break;
                }
            }
        }
    }
    reverse(res.begin(),res.end());
    if(res.length()==0) res="nai";
    cout << res;
    return 0;
}