#include<iostream>
#include<vector>
using namespace std;
//并查集
//邻接表
const int maxv=1010;
int n;
vector<int> Adj[maxv];
bool vis[maxv]={false};
int father[maxv];
int currentPoint;
int findFather(int x)
{
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void Union(int a,int b)
{
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}
void init()
{
    for(int i=1;i<=n;i++){
        vis[i]=false;
        father[i]=i;
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
        cin >> currentPoint;
        init();
        int block=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<Adj[i].size();j++){
                int u=i,v=Adj[i][j];
                if(u==currentPoint || v==currentPoint) continue;
                Union(u,v);
            }
        }
        for(int i=1;i<=n;i++){
            if(i==currentPoint) continue;
            int faI=findFather(i);
            if(vis[faI]==false){
                block++;
                vis[faI]=true;
            }
        }
        cout << block-1 << "\n";
    }
    return 0;
}