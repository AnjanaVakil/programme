#include<iostream>
#include<vector>
using namespace std;
//14
//思路有bug
int main()
{
    string s,p;
    cin >> s >> p;
    string res;
    int slen=s.length(),plen=p.length();
    int minlen=slen+1;
    char c=p[plen-1];
    int fa,fb;
    for(int i=0;i<slen;i++){
        if(s[i]==p[0]){
            int j=i;
            while(s[j]!=c) j++;
            if(j-i+1<minlen){
                minlen=j-i+1;
                fa=i;
                fb=j;
            }
        }
    }
    for(int i=fa;i<=fb;i++){
        cout << s[i];
    }
    return 0;
}