#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//25‘
const int maxn=110;
vector<int> v[maxn];
int level[maxn]; //记录每个结点的层数
int gen[maxn]; //gen记录level层的结点个数
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    //下面这句很重要 root的level是 1
    level[root]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        gen[level[front]]++;
        for(int i=0;i<v[front].size();i++){
            int childindex=v[front][i];
            level[childindex]=level[front]+1;
            q.push(childindex);
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
            v[id].push_back(ids);
        }
    }
    bfs(1);
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