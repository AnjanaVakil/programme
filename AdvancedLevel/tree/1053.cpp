#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100;
struct node{
    int weight;
    vector<int> child;
}Node[maxn];
int n,m,S;
bool cmp(int a,int b)
{
    return Node[a].weight>Node[b].weight;
}
int path[maxn];//记录路径
//numNode当前路径上的结点个数
void DFS(int index,int numNode,int sum)
{
    if(sum>S) return;
    if(sum==S){
        if(Node[index].child.size()==0){
            //到达叶结点
            for(int i=0;i<numNode;i++){
                cout << Node[path[i]].weight;
                if(i<numNode-1) cout << " ";
                else cout << "\n";
            }
        }else{
            return;
        }
    } 
    if(sum<S){
        for(int i=0;i<Node[index].child.size();i++){
            int child=Node[index].child[i];
            path[numNode]=child;
            DFS(child,numNode+1,sum+Node[child].weight);
        }
    }
}
int main()
{
    cin >> n >> m >> S;
    for(int i=0;i<n;i++){
        cin >> Node[i].weight;
    }
    int father,k,child;
    for(int i=0;i<m;i++){
        cin >> father >> k;
        for(int j=0;j<k;j++){
            cin >> child;
            Node[father].child.push_back(child);
        }
        //child结点按照weight排序，这样会优先遍历到weight大的子结点
        sort(Node[father].child.begin(),Node[father].child.end(),cmp);
    }
    path[0]=0;
    DFS(0,1,Node[0].weight);
    return 0;
}