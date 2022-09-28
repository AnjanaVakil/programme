#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int> Node[maxn];
int maxDepth=-1,num;
void dfs(int index,int depth)
{
    //递归边界 很重要
    if(Node[index].size()==0){
        if(depth>maxDepth){
            maxDepth=depth;
            num=1;
        }else if(depth==maxDepth){
            num++;
        }
        return;
    }
    for(int i=0;i<Node[index].size();i++){
        dfs(Node[index][i],depth+1);
    }
}
int main()
{
    int n;
    double p,r;
    cin >> n >> p >> r;
    r/=100.0;
    int t,root;
    for(int i=0;i<n;i++){
        cin >> t;
        if(t==-1){
            root=i;
        }else{
            Node[t].push_back(i);
        }
    }
    dfs(root,0);
    printf("%.2f %d",p*pow(1+r,maxDepth),num);
    return 0;
}