#include<iostream>
#include<vector>
using namespace std;
//25'
vector<vector<int> > Adj;
vector<bool> vis;
int n,m;
int cnt=0;
void DFS(int u)
{
    vis[u]=true;
    cnt++;
    for(int v=0;v<Adj[u].size();v++){
        if(vis[Adj[u][v]]==false){
            DFS(Adj[u][v]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    Adj.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    //even偶数 odd奇数 分清楚
    int even=0;
    //要统计无向图中顶点的度数，使用邻接表更方便，Adj[i].size就是度数
    for(int i=1;i<=n;i++){
        printf("%d",Adj[i].size());
        if(Adj[i].size()%2==0) even++;
        if(i!=n) printf(" ");
        else printf("\n");
    }
    DFS(1);
    //从结点1开始DFS，如果最后发现统计的连通结点个数cnt != n说明是不是连通图
    //cnt!=n 不是连通图
    if(cnt==n && even==n){
        printf("Eulerian");
    }else if(cnt==n && even==n-2){
        printf("Semi-Eulerian");
    }else{
        printf("Non-Eulerian");
    }
    return 0;
}