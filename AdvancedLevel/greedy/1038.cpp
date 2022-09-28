#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//16:11-16:30 没写出来
bool cmp(string a,string b)
{
    //不是按照字典序排列就可以的
    //必须保证两个字符串构成的数字是最小的才行
    return a+b<b+a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),cmp);
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] << " ";
    // }
    string res;
    for(int i=0;i<v.size();i++){
        res+=v[i];
    }
    while(res[0]=='0' && res.length()!=0){
        res.erase(res.begin());
    }
    if(res.length()==0) cout << 0;
    cout << res;
    return 0;
}