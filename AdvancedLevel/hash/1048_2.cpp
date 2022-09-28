#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int hash[1005]={0};
    int coin;
    for(int i=0;i<n;i++){
        cin >> coin;
        hash[coin]++;
    }
    for(int i=0;i<m;i++){
        if(hash[i]>0 && hash[m-i]>0){
            if(i==m-i && hash[i]<=1){
                continue;
            }
            cout << i << " " << m-i;
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}