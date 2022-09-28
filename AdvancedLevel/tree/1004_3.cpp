#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn=110;
vector<int> node[maxn];
int leaf[maxn]={0},maxdepth=-1;//maxdepth记录树的深度(高度)
int depth[maxn]={0};//各结点所处的层号,从1开始
void BFS(int root)
{
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        maxdepth=max(maxdepth,depth[front]);
        if(node[front].size()==0){
            leaf[depth[front]]++;
        }
        for(int i=0;i<node[front].size();i++){
            depth[node[front][i]]=depth[front]+1;
            Q.push(node[front][i]);
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int father,k,child;
        cin >> father >> k;
        for(int j=0;j<k;j++){
            cin >> child;
            node[father].push_back(child);
        }
    }
    depth[1]=1;
    BFS(1);
    for(int i=1;i<=maxdepth;i++){
        if(i!=1) cout << " ";
        cout << leaf[i];
    }
    return 0;
}