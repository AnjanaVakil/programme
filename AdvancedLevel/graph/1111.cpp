#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv=510;
const int inf=1e9;
int G[maxv][maxv],cost[maxv][maxv];
int dis[maxv],Time[maxv],dispre[maxv],timepre[maxv];
int weight[maxv],nodeNum[maxv];
bool vis[maxv]={false};
vector<int> dispath,timepath,temppath;
int n,st;
void dijkstradis(int s)
{
    for(int i=0;i<n;i++){
        dispre[i]=i;
    }
    dis[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false && G[u][v]!=inf){
                if(dis[u]+G[u][v]<dis[v]){
                    dis[v]=dis[u]+G[u][v];
                    dispre[v]=u;
                    weight[v]=weight[u]+cost[u][v];
                }else if(dis[u]+G[u][v]==dis[v] && weight[u]+cost[u][v]<weight[v]){
                    //最短路径相同,如果相同求时间最短
                    weight[v]=weight[u]+G[u][v];
                    dispre[v]=u;
                }
            }
        }
    }
}
void dijkstratime(int s)
{
    Time[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && Time[j]<MIN){
                u=j;
                MIN=Time[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(Time[u]+cost[u][v]<Time[v]){
                Time[v]=Time[u]+cost[u][v];
                timepre[v]=u;
                nodeNum[v]=nodeNum[u]+1;
            }else if(Time[u]+cost[u][v]==Time[v]){
                //时间最少，如果相同求结点数最少
                if(nodeNum[v]>nodeNum[u]+1){
                    timepre[v]=u;
                    nodeNum[v]=nodeNum[u]+1;
                }
            }

        }
    }
}
void dfsdispath(int v)
{
    dispath.push_back(v);
    if(v==st) return;
    dfsdispath(dispre[v]);
}
void dfstimepath(int v)
{
    timepath.push_back(v);
    if(v==st) return;
    dfstimepath(timepre[v]);
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    int a,b,flag,len,t;
    fill(G[0],G[0]+maxv*maxv,inf);
    fill(cost[0],cost[0]+maxv*maxv,inf);
    fill(dis,dis+maxv,inf);
    fill(Time,Time+maxv,inf);
    fill(weight,weight+maxv,inf);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d%d",&a,&b,&flag,&len,&t);
        G[a][b]=len;
        cost[a][b]=t;
        if(flag!=1){
            G[b][a]=len;
            cost[b][a]=t;
        }
    }
    int fin;
    scanf("%d%d",&st,&fin);
    dijkstradis(st);
    dfsdispath(fin);
    fill(vis,vis+maxv,false);
    dijkstratime(st);
    dfstimepath(fin);
    printf("Distance = %d",dis[fin]);
    if(dispath==timepath){
        printf("; Time = %d: ", Time[fin]);
    }else{
        printf(": ");
        for(int i=dispath.size()-1;i>=0;i--){
            printf("%d",dispath[i]);
            if(i!=0) printf(" -> ");
        }
        printf("\nTime = %d: ",Time[fin]);
    }
    for(int i=timepath.size()-1;i>=0;i--){
        printf("%d",timepath[i]);
        if(i!=0) printf(" -> ");
    }
    return 0;
}