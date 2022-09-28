#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1020;
const int INF=1e9;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn]={false};
int n,m,k,ds;
vector<int> pre;
int MinDis=-1;
void Dijkstra(int s)
{
    fill(d,d+maxn,INF);
    memset(vis,false,sizeof(vis));
    //循环n+m次
    d[s]=0;
    for(int i=0;i<n+m;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=1;v<=n+m;v++){
            if(vis[v]==false && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                }
            }
        }
    }
}
int main()
{
    //such a location that the minimum distance between the station and any of the residential housing is as far away as possible.
    //加油站距离最近的居民房尽可能的远 
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    fill(G[0],G[0]+maxn*maxn,INF);
    string a,b;
    int x,y;
    int dis;
    for(int i=0;i<k;i++){
        //使用scanf输入，但是输入string类型可以混杂cin
        cin >> a >> b;
        if(a[0]=='G'){
            a=a.substr(1);
            x=n+stoi(a);
        }else{
            x=stoi(a);
        }
        if(b[0]=='G'){
            b=b.substr(1);
            y=n+stoi(b);
        }else{
            y=stoi(b);
        }
        scanf("%d",&G[x][y]);
        G[y][x]=G[x][y];
    }
    int ansId=-1;
    double ansDis=-1,ansAvg=INF;
    for(int i=n+1;i<=n+m;i++){
        Dijkstra(i);
        double minDis=INF,avg=0;
        for(int j=1;j<=n;j++){
            if(d[j]>ds){
                minDis=-1;
                break;
            }
            if(d[j]<minDis) minDis=d[j];
            avg+=1.0*d[j];
        }
        if(minDis==-1) continue;
        avg=avg/n;
        if(minDis>ansDis){
            ansId=i;
            ansDis=minDis;
            ansAvg=avg;
        }else if(minDis==ansDis && avg<ansAvg){
            ansId=i;
            ansAvg=avg;
        }
    }
    if(ansId==-1){
        printf("No Solution");
    }else{
        printf("G%d\n%.1f %.1f",ansId-n,ansDis,ansAvg);
    }
    return 0;
}