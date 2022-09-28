#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxv=10010;
vector<int> Adj[maxv];
int n,maxdepth;
vector<int> temp,ans;
int father[maxv];
int isRoot[maxv];
void init()
{
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}
int findFather(int x)
{
    while(x!=father[x]){
        x=father[x];
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
void DFS(int u,int depth,int pre)
{
    if(depth>maxdepth){
        maxdepth=depth;
        temp.clear();
        temp.push_back(u);
    }else if(depth==maxdepth){
        temp.push_back(u);
    }
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(v==pre) continue;
        DFS(v,depth+1,u);
    }
}
int calBlock()
{
    int block=0;
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]=1;
    }   
    for(int i=1;i<=n;i++){
        block+=isRoot[i];
    }
    return block;
}
int main()
{
    cin >> n;
    int a,b;
    init();
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
        Union(a,b);
    }
    int block=calBlock();
    if(block!=1){
        cout << "Error: " << block << " components";
    }else{
        maxdepth=0;
        DFS(1,1,-1);
        ans=temp;
        DFS(ans[0],1,-1);
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        sort(ans.begin(),ans.end());
        cout << ans[0] << "\n";
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                cout << ans[i] << "\n";
            }
        }
    }
    return 0;
}