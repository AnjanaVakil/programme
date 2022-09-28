#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//邻接表
const int maxv=1010;
int n;
vector<int> Adj[maxv];
bool vis[maxv]={false};
int lost;
void DFS(int u)
{
    if(u==lost) return;
    vis[u]=true;
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(vis[v]==false){
            DFS(v);
        }
    }
}
int main()
{
    int m,k,a,b;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    for(int i=0;i<k;i++){
        cin >> lost;
        memset(vis,false,sizeof(vis));
        int block=0;
        for(int u=1;u<=n;u++){
            if(u!=lost && vis[u]==false){
                DFS(u);
                block++;
            }
        }
        cout << block-1 << "\n";
    }
    return 0;
}