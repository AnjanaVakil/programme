//17:55-18:02 20'
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s;
    stack<string> sta;
    while(cin >> s){
        sta.push(s);
        if(cin.get()=='\n') break;
    }
    string res="";
    while(!sta.empty()){
        res+=sta.top();
        res+=" ";
        sta.pop();
    }
    for(int i=0;i<res.length()-1;i++){
        cout << res[i];
    }
    return 0;
}