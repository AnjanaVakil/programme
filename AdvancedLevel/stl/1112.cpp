#include<iostream>
#include<set>
using namespace std;
//20' 没写出来
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int hash[256]={0};
    set<char> keys;
    hash[s[0]]=1;
    // for(int i=0;i<s.length();i++){
    //     hash[s[i]]++;
    // }
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i-1] && s[i]!=s[i+1]){
            hash[s[i]]=1;
        }
    }
    for(int i=1;i<s.length();i++){
        string t=s.substr(i,k);
        int j;
        for(j=1;j<t.length();j++){
            if(t[j]!=t[j-1]){
                break;
            }
        }
        if(j==t.length()){
            if(hash[t[0]]==1){
                keys.insert(t[0]);
                s.erase(i+1,k-1);
            }
        }
    }
    for(auto it=keys.begin();it!=keys.end();it++){
        cout << *it;
    }
    cout << "\n" << s << "\n";
    return 0;
}