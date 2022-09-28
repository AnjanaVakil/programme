//18:18-23 20'
#include<iostream>
#include<vector>
using namespace std;
string rep[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
    string s;
    cin >> s;
    int sum=0;
    for(int i=0;i<s.length();i++){
        sum+=(s[i]-'0');
    }
    vector<string> ans;
    while(sum){
        ans.push_back(rep[sum%10]);
        sum/=10;
    }
    for(int i=ans.size()-1;i>0;i--){
        cout << ans[i] << " ";
    }
    cout << ans[0];
    return 0;
}