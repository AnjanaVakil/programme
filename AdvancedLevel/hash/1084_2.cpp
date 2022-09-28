#include<iostream>
using namespace std;
int main()
{
    string s,t,ans;
    cin >> s >> t;
    for(int i=0;i<s.length();i++){
        if(t.find(s[i])==string::npos && ans.find(toupper(s[i]))==string::npos){
            ans+=toupper(s[i]);
        }
    }
    cout << ans;
    return 0;
}