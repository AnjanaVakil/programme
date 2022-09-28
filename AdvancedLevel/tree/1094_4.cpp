#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//25'
const int maxn=110;
struct node{
    vector<int> child;
    int layer;
}v[maxn];
int gen[maxn]; //gen记录每层的结点个数
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    //下面这句很重要 root的level是 1
    v[root].layer=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        gen[v[front].layer]++;
        for(int i=0;i<v[front].child.size();i++){
            int child=v[front].child[i];
            v[child].layer=v[front].layer+1;
            q.push(child);
        }
    }
}
int main()
{
    int n,m,id,k;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> id >> k;
        int temp,ids;
        for(int j=0;j<k;j++){
            cin >> ids;
            v[id].child.push_back(ids);
        }
    }
    bfs(1);
    //不论是dfs还是bfs，求有最大结点数的层数，比大小的操作必须放在遍历完树中所有的结点
    int maxgen=-1,maxlevel=-1;
    for(int i=0;i<maxn;i++){
        if(gen[i]>maxgen){
            maxgen=gen[i];
            maxlevel=i;
        }
    }
    printf("%d %d",maxgen,maxlevel);
    return 0;
}