#include<iostream>
using namespace std;
int main()
{
    string s;
    int N,j;
    cin >> s >> N;
    //1 8 
    //1,11,12,1121,122111,112213,122211231,1123123111,
    for(int cnt=1;cnt<N;cnt++){
        string t;
        for(int i=0;i<s.length();i=j){
            for(j=i;j<s.length() && s[j]==s[i];j++);
            t+=(s[i]+to_string(j-i));
        }
        s=t;
    }
    cout << s;
    return 0;
}