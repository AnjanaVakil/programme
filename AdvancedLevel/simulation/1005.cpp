#include<iostream>
using namespace std;
string res[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
    string s;
    cin >> s;
    int sum=0;
    for(int i=0;i<s.length();i++){
        sum+=(s[i]-'0');
    }
    string t=to_string(sum);
    for(int i=0;i<t.length();i++){
        if(i!=0){
            cout << " ";
        }
        cout << res[t[i]-'0'];
    }
    return 0;
}