#include<iostream>
#include<vector>
using namespace std;
int a[1005][105],sum[1005];
int main()
{
    int n,m,maxn=0,first=1;
    // vector<int> ans;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            sum[j]+=a[i][j];
            maxn=max(maxn,sum[j]);
        }
    }
    cout << maxn << endl;
    for(int j=1;j<=n;j++){
        if(sum[j]==maxn){
            if(!first) cout << " ";
            cout << j;
            first=0;
        }
    }
    // for(int j=1;j<=n;j++){
    //     if(sum[j]==maxn) ans.push_back(j);
    // }
    // for(int i=0;i<ans.size();i++){
    //     if(i!=0) cout << " ";
    //     cout << ans[i];
    // }
    return 0;
}