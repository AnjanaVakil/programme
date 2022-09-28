#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//14'
int main()
{
    string s,p;
    cin >> s >> p;
    string res;
    int slen=s.length(),plen=p.length();
    int minlen=INT_MAX;
    char c=p[plen-1];
    for(int i=0;i<slen;i++){
        if(s[i]==p[0]){
            if(s.find(c,i)!=string::npos){
                int t=s.find(c,i);
                if(t-i+1<minlen){
                    minlen=t-i+1;
                    //substr函数还是没记住 s.substr(pos,n);
                    res=s.substr(i,t-i+1);
                }
            }
        }
    }
    cout << res;
    return 0;
}