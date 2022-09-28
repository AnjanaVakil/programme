#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//45-18 30'
const int maxn=110;
struct Node{
    vector<int> child;
    int weight;
}node[maxn];
int path[maxn];
bool cmp(int a,int b)
{
    return node[a].weight>node[b].weight;
}
int n,m,s;
void dfs(int index,int tempsum,int numnode)
{
    if(tempsum>s) return;
    if(tempsum==s){
        if(node[index].child.size()==0){
            for(int i=0;i<numnode;i++){
                cout << node[path[i]].weight;
                if(i!=numnode-1) cout << " ";
                else cout << '\n';
            }
        }else{
            return;
        }
    }
    if(tempsum<s){
        for(int i=0;i<node[index].child.size();i++){
            int child=node[index].child[i];
            path[numnode]=child;
            dfs(child,tempsum+node[child].weight,numnode+1);
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    for(int i=0;i<n;i++){
        cin >> node[i].weight;
    }
    int id,k;
    for(int i=0;i<m;i++){
        cin >> id >> k;
        int ids;
        for(int j=0;j<k;j++){
            cin >> ids;
            node[id].child.push_back(ids);
        }
        //child结点按照weight排序，这样会优先遍历到weight大的子结点
        //这样就会优先遍历weight大的结点,符合题目要求
        sort(node[id].child.begin(),node[id].child.end(),cmp);
    }
    path[0]=0;
    dfs(0,node[0].weight,1);
    return 0;
}