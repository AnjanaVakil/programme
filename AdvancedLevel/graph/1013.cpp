#include<iostream>
using namespace std;
//添加的边数=连通块数-1
//图的遍历，统计强连通分量的个数，dfs
//邻接矩阵
const int maxv=1010;
int G[maxv][maxv];
int n;
bool vis[maxv]={false};
void DFS(int u)
{
    vis[u]=true;
    for(int v=1;v<=n;v++){
        if(vis[v]==false && G[u][v]==1){
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
        G[a][b]=G[b][a]=1;
    }
    int lost;
    for(int i=0;i<k;i++){
        fill(vis,vis+maxv,false);
        cin >> lost;
        int cnt=0;
        //vis[lost]=true，能起到删除顶点的作用
        vis[lost]=true;
        for(int u=1;u<=n;u++){
            if(vis[u]==false){
                DFS(u);
                cnt++;
            }
        }
        cout << cnt-1 << "\n";
    }
    return 0;
}