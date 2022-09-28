#include<iostream>
#include<vector>
using namespace std;
const int maxv=210;
int G[maxv][maxv];
int main()
{
    int nv,ne,a,b;
    cin >> nv >> ne;
    for(int i=0;i<ne;i++){
        cin >> a >> b;
        G[a][b]=G[b][a]=1;
    }
    int m,k;
    cin >> m;
    //clique:every two distinct vertices in the clique are adjacent.
    for(int i=0;i<m;i++){
        cin >> k;
        vector<int> v(k);
        int exist[maxv]={0};
        for(int j=0;j<k;j++){
            cin >> v[j];
            exist[v[j]]=1;
        }
        int is=1,isMax=1;
        for(int j=0;j<k;j++){
            if(is==0) break;
            for(int t=j+1;t<k;t++){
                if(G[v[j]][v[t]]==0){
                    is=0;
                    cout << "Not a Clique\n";
                    break;
                }
            }
        }
        if(is==0) continue;
        for(int j=1;j<=nv;j++){
            if(exist[j]==0){
                for(int t=0;t<k;t++){
                    if(G[j][v[t]]==0) break;
                    if(t==k-1) isMax=0;
                }
            }
            if(isMax==0){
                cout << "Not Maximal\n";
                break;
            }
        }
        if(isMax==1) cout << "Yes\n";
    }
    return 0;
}