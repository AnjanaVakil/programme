#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // int n,t;
    int n;
    cin >> n;
    // vector<int> v;
    // for(int i=0;i<n;i++){
    //     cin >> t;
    //     v.push_back(t);
    // }
    vector<int> v(n);
    for(int i=0;i<n;i++){
       cin >> v[i];
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    int res=v[0];
    for(int i=1;i<v.size();i++){
        res=(v[i]+res)/2;
    }
    cout << res;
    return 0;
}