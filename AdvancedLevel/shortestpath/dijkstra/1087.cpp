#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int maxn=220;
const int INF=1e9;
int G[maxn][maxn];
int d[maxn];
int n,k;
string st;
map<string,int> m;
map<int,string> m2;
int weight[maxn];
bool vis[maxn]={false};
//num 最短路径条数
//pre 保存最短路径 pt 保存最短路径上的顶点数
int num[maxn],pre[maxn],pt[maxn];
int w[maxn];
void Dijkstra(int s)
{
    fill(d,d+maxn,INF);
    memset(w,0,sizeof(w));
    memset(num,0,sizeof(num));
    memset(pt,0,sizeof(pt));
    for(int i=0;i<n;i++) pre[i]=i;
    d[s]=0;
    num[s]=1;
    w[s]=weight[s];
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
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                    pre[v]=u;
                    pt[v]=pt[u]+1;
                }else if(d[u]+G[u][v]==d[v]){
                    num[v]+=num[u];
                    if(w[u]+weight[v]>w[v]){
                        w[v]=w[u]+weight[v];
                        pre[v]=u;
                        pt[v]=pt[u]+1;
                    }else if(w[u]+weight[v]==w[v]){
                        double uAvg=1.0*(w[u]+weight[v])/(pt[u]+1);
                        double vAvg=1.0*(w[v])/pt[v];
                        if(uAvg>vAvg){
                            pre[v]=pre[u];
                            pt[v]=pt[u]+1;
                        }
                    }
                }
            }
        }
    }
}
void dfs(int v)
{
    if(v==0){
        cout << m2[v];
        return;
    }
    dfs(pre[v]);
    cout << "->" << m2[v];
}
int main()
{
    cin >> n >> k >> st;
    fill(G[0],G[0]+maxn*maxn,INF);
    m[st]=0;
    m2[0]=st;
    string t;
    for(int i=1;i<n;i++){
        cin >> t >> weight[i];
        m[t]=i;
        m2[i]=t;
    }
    string c1,c2;
    for(int i=0;i<k;i++){
        cin >> c1 >> c2;
        cin >> G[m[c1]][m[c2]];
        G[m[c2]][m[c1]]=G[m[c1]][m[c2]];
    }
    Dijkstra(0);
    int rom=m["ROM"];
    cout << num[rom] << " " << d[rom] << " " << w[rom] << " " << w[rom]/pt[rom] << endl;
    dfs(rom);
    return 0;
}