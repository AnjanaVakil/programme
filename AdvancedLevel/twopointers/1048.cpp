#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> coin(n);
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    sort(coin.begin(),coin.end());
    // 默认升序
    // for(int i=0;i<n;i++){
    //     cout << coin[i] << " ";
    // }
    // cout << endl;
    int low=0,high=n-1;
    while(low<high){
        if(coin[low]+coin[high]==m){
            cout << coin[low] << " " << coin[high];
            return 0;
        }else if(coin[low]+coin[high]<m){
            low++;
        }else{
            high--;
        }
    }
    cout << "No Solution";
    return 0;
}