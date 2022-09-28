#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//13:52-14:03 20' 运行超时
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> coin(n);
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    sort(coin.begin(),coin.end());
    //默认升序
    // for(int i=0;i<n;i++){
    //     cout << coin[i] << " ";
    // }
    // cout << endl;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(coin[i]+coin[j]==m){
                cout << coin[i] << " " << coin[j];
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==0){
        cout << "No Solution";
    }
    return 0;
}