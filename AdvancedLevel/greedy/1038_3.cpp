//13:06-23 28'(30')
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string a,string b)
{
    return a+b<b+a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    string res;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),cmp);
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