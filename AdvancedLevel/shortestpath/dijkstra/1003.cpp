#include<iostream>
#include<cstring>
using namespace std;
const int maxn=510;
const int INF=1e9;
int G[maxn][maxn],team[maxn];
int n,m,st,ed;
int d[maxn],weight[maxn],num[maxn];
bool vis[maxn]={false};
void Dijkstra(int s)
{
    fill(d,d+maxn,INF);
    memset(weight,0,sizeof(weight));
    memset(num,0,sizeof(num));
    d[s]=0;
    weight[s]=team[s];
    num[s]=1;
    for(int i=0;i<n;i++){
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
            if(vis[v]==false && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    weight[v]=weight[u]+team[v];
                    num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){
                    if(weight[u]+team[v]>weight[v]){
                        weight[v]=weight[u]+team[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> st >> ed;
    for(int i=0;i<n;i++){
        cin >> team[i];
    }
    //初始化图
    fill(G[0],G[0]+maxn*maxn,INF);
    int x,y,len;
    for(int i=0;i<m;i++){
        cin >> x >> y >> len;
        G[x][y]=len;
        G[y][x]=len;
    }
    Dijkstra(st);
    cout <<  num[ed] << " " << weight[ed];
    return 0;
}