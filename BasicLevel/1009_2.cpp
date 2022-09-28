#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s;
    stack<string> v;
    while(cin >> s){
        v.push(s);
        if(cin.get()=='\n') break;
    }
    // cout << v.top();
    // v.pop();
    // while(!v.empty()){
    //     cout << " " << v.top();
    //     v.pop();
    // }
    while(!v.empty()){
        if(v.size()==1) cout << v.top();
        else cout << v.top() << " ";
        v.pop();
    }
    return 0;
}