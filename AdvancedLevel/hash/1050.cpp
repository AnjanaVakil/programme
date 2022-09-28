#include<iostream>
#include<vector>
using namespace std;
//17:49-57 8min AC
//They are students. aeiou
//Thy r stdnts.
int main()
{
    string s,t;
    vector<char> res;
    getline(cin,s);
    getline(cin,t);
    for(int i=0;i<s.length();i++){
        if(t.find(s[i])==string::npos){
            res.push_back(s[i]);
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i];
    }
    return 0;
}