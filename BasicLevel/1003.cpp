#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n,p=0,t=0;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            if(s[i]=='P') p=i;
            if(s[i]=='T') t=i;
        }
        if(m['P']==1 && m['A']!=0 && m['T']==1 && m.size()==3 && t-p!=1 && p*(t-p-1)==s.length()-t-1) 
            printf("YES\n");
        else printf("NO\n");
    }
}