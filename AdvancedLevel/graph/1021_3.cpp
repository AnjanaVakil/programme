#include<iostream>
#include<vector>
#include<set>
using namespace std;
//25'
const int maxn=10010;
int G[maxn][maxn];
bool vis[maxn]={false};
int n;
int depth,maxdepth;
vector<int> temp;
set<int> s;
void dfs(int u,int depth)
{
    if(depth>maxdepth){
        maxdepth=depth;
        temp.clear();
        temp.push_back(u);
    }else if(depth==maxdepth){
        temp.push_back(u);
    }
    vis[u]=true;
    for(int v=1;v<=n;v++){
        if(vis[v]==false && G[u][v]==1){
            dfs(v,depth+1);
        }
    }
}
int main()
{
    cin >> n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        G[a][b]=G[b][a]=1;
    }
    int cnt=0;
    int s1;
    for(int u=1;u<=n;u++){
        if(vis[u]==false){
            dfs(u,1);
            if(u==1){
                //从一个结点dfs后保留最高高度拥有的结点们，
                //然后从这些结点中的任意一个开始dfs得到最高高度的结点们，
                //这两个结点集合的并集就是所求结点
                if(temp.size()!=0) s1=temp[0];
                for(int j=0;j<temp.size();j++){
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }
    if(cnt>1){
        printf("Error: %d components",cnt);
    }else{
        //这三行再次初始化别忘记了
        temp.clear();
        maxdepth=0;
        fill(vis,vis+maxn,false);
        dfs(s1,1);
        for(int i=0;i<temp.size();i++){
            s.insert(temp[i]);
        }
        for(auto it=s.begin();it!=s.end();it++){
            cout << *it << endl;
        }
    }
    return 0;
}