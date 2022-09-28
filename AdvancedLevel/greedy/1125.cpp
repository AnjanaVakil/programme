#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 14:55-15:07 25score
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    //8
    //10 15 12 3 4 13 1 15
    //1 3 4 10 12 13 15 15
    //2 3 6 9 10 11 13 14
    sort(v.begin(),v.end());
    int res=v[0];
    for(int i=1;i<n;i++){
        res=(res+v[i])/2;
    }
    cout << res;
    return 0;
}