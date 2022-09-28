#include<iostream>
#include<vector>
using namespace std;
const int maxn=110;
vector<int> node[maxn];
int leaf[maxn]={0},maxdepth=-1;//maxdepth记录树的深度(高度)
void DFS(int index,int depth)
{
    if(node[index].size()==0){
        //不是leaf[index]++,而是leaf[depth]++
        //统计的是每一层的叶子结点数
        //leaf[index]++; 这是错误的!
        leaf[depth]++;
        maxdepth=max(maxdepth,depth);
        return;
    }
    for(int i=0;i<node[index].size();i++){
        DFS(node[index][i],depth+1);
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
    DFS(1,1); //index:1 depth:1
    for(int i=1;i<=maxdepth;i++){
        if(i!=1) cout << " ";
        cout << leaf[i];
    }
    return 0;
}