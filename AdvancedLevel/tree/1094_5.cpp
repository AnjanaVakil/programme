#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//25'
const int maxn=110;
vector<int> v[maxn];
int gen[maxn]; //gen记录每层的结点个数
void dfs(int index,int depth)
{
    gen[depth]++;
    for(int i=0;i<v[index].size();i++){
        dfs(v[index][i],depth+1);
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
    dfs(1,1);
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