#include<iostream>
#include<vector>
using namespace std;
const int maxn=510;
const int INF=1e9;
int G[maxn][maxn];
int cmax,n,ed,m;
int bike[maxn];
int d[maxn];
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> path,tempPath;
int minRemain=INF,minNeed=INF;
void Dijkstra(int s)
{
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<=n;j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<=n;v++){
            if(vis[v]==false && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v)
{
    if(v==0){
        tempPath.push_back(v);
        int need=0,remain=0;
        //And more, all the stations on the way will be adjusted as well.
        for(int i=tempPath.size()-1;i>=0;i--){
            int id=tempPath[i];
            if(bike[id]>0){
                remain+=bike[id];
            }else{
                if(remain>abs(bike[id])){
                    remain-=abs(bike[id]);
                }else{
                    need+=abs(bike[id])-remain;
                    remain=0;
                }
            }
        }
        if(need<minNeed){
            minNeed=need;
            minRemain=remain;
            path=tempPath;
        }else if(need==minNeed && remain<minRemain){
            minRemain=remain;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main()
{
    //还是少使用cin cout吧，速度很慢
    scanf("%d%d%d%d",&cmax,&n,&ed,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&bike[i]);
        bike[i]-=(cmax/2);
    }
    int a,b;
    fill(G[0],G[0]+maxn*maxn,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        scanf("%d",&G[a][b]);
        G[b][a]=G[a][b];
    }
    Dijkstra(0);
    DFS(ed);
    printf("%d ",minNeed);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d",path[i]);
        if(i!=0) printf("->");
    }
    printf(" %d",minRemain);
    return 0;
}