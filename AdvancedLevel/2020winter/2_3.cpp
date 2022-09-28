#include<iostream>
#include<vector>
using namespace std;
//25'
int main()
{
    string s,p;
    cin >> s >> p;
    string res;
    int slen=s.length(),plen=p.length();
    int minlen=slen+1;
    char c=p[plen-1];
    for(int i=0;i<slen;i++){
        if(s[i]==p[0]){
            int pos=0;
            int j=i;
            while(j<slen){
                if(s[j]==p[pos]){
                    j++;
                    pos++;
                }else{
                    j++;
                }
                if(pos==plen){
                    if(j-i<minlen){
                        minlen=j-i;
                        res=s.substr(i,j-i);
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}