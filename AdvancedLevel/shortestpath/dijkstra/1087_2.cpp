#include<iostream>
#include<cstring>
#include<map>
#include<vector>
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
vector<int> pre[maxn];
vector<int> path,tempPath;
int maxWei=-1,numPath=0;
double maxAvg;
void Dijkstra(int s)
{
    fill(d,d+maxn,INF);
    d[s]=0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfs(int v)
{
    if(v==0){
        numPath++;
        tempPath.push_back(v);
        int tempWei=0;
        for(int i=tempPath.size()-1;i>=0;i--){
            int id=tempPath[i];
            tempWei+=weight[id];
        }
        double tempAvg=1.0*tempWei/(tempPath.size()-1);
        if(tempWei>maxWei){
            maxWei=tempWei;
            maxAvg=tempAvg;
            path=tempPath;
        }else if(tempWei==maxWei && tempAvg>maxAvg){
            maxAvg=tempAvg;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
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
    dfs(rom);
    cout << numPath << " " << d[rom] << " " << maxWei << " " << (int)maxAvg << endl;
    for(int i=path.size()-1;i>=0;i--){
        cout << m2[path[i]];
        if(i!=0) cout << "->";
    }
    return 0;
}