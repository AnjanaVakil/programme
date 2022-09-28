#include<iostream>
using namespace std;
//伪代码
//s起点
Dijkstra(G,d[],s)
{
    初始化;
    for(循环n次){
        u=使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for(从u出发能到达的所有顶点v){
            if(v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]最优){
                优化d[v];
            }
        }
    }
}
//邻接矩阵
const int maxv=1010;
const int INF=1e9;
int n,G[maxv][maxv];
bool vis[maxv]={false};
void Dijkstra(int s)
{
    fill(d,d+maxv,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        //找到未访问的顶点中d最小的
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]){
                d[v]=d[u]+G[u][v];
            }
        }
    }
}
//邻接表
struct Node{
    int v,dis;
};
vector<Node>Adj[maxv];
int n,d[maxv];
bool vis[maxv]={false};
void Dijkstra(int s)
{
    fill(d,d+maxv,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]>MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            if(vis[v]==false && d[u]+Adj[u][j].dis<d[v]){
                d[v]=d[u]+Adj[u][j].dis;
            }
        }
    }
}


