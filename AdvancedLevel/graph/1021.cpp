#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxv=10010;
vector<int> Adj[maxv];
int n,maxdepth;
bool vis[maxv]={false};
set<int> s;
vector<int> temp;
void DFS(int u,int depth)
{
    if(depth>maxdepth){
        maxdepth=depth;
        temp.clear();
        temp.push_back(u);
    }else if(depth==maxdepth){
        temp.push_back(u);
    }
    vis[u]=true;
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(vis[v]==false){
            DFS(v,depth+1);
        }
    }
}
int main()
{
    cin >> n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int block=0,s1=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            DFS(i,1);
            if(i==1){
                if(temp.size()!=0) s1=temp[0];
                for(int j=0;j<temp.size();j++){
                    s.insert(temp[j]);
                }
            }
            block++;
        }
    }
    if(block>=2){
        cout << "Error: " << block << " components";
    }else{
        temp.clear();
        maxdepth=0;
        fill(vis,vis+maxv,false);
        DFS(s1,1);
        for(int i=0;i<temp.size();i++){
            s.insert(temp[i]);
        }
        for(auto it=s.begin();it!=s.end();it++){
            cout << *it << "\n";
        }
    }
    return 0;
}