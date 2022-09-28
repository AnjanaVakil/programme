#include<iostream>
#include<set>
using namespace std;
bool sureNoBroken[256];
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int hash[256]={0};
    set<char> keys;
    //这里的pre和s都加上了一个字符串中不可能有的字符
    char pre='#';
    s=s+'#';
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==pre){
            cnt++;
        }else{
            if(cnt%k!=0){
                sureNoBroken[pre]=true;
            }
            cnt=1;
        }
        if(i!=s.length()-1) hash[s[i]]=(cnt%k==0);
        pre=s[i];
    }
    for(int i=0;i<s.length()-1;i++){
        if(sureNoBroken[s[i]==true]){
            hash[s[i]]=0;
        }
    }
    for(int i=1;i<s.length()-1;i++){
        if(hash[s[i]]==1 && keys.find(s[i])==keys.end()){
            cout << s[i];
            keys.insert(s[i]);
        }
    }
    cout << endl;
    for(int i=0;i<s.length()-1;i++){
        cout << s[i];
        if(hash[s[i]]==1){
            i=i+k-1;
        }
    }
    return 0;
}