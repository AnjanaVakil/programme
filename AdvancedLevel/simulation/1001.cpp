#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int sum=a+b;
    string s=to_string(sum);
    int len=s.length();
    vector<char> v;
    //完全可以不用vector v,可以直接输出！！！
    for(int i=0;i<len;i++){
        v.push_back(s[i]);
        if(s[i]=='-'){
            continue;
        }
        if((len-i-1)%3==0 && i!=len-1) v.push_back(',');
    }
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    return 0;   
}