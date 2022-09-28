#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int> child[maxn]; //vector数组
int maxDepth,num;//num最大深度的叶结点个数
void DFS(int index,int depth)
{
    //递归边界
    if(child[index].size()==0){//到达叶结点
        if(depth>maxDepth){
            maxDepth=depth;
            num=1;
        }else if(depth==maxDepth){
            num++;
        }
        return;
    }
    for(int i=0;i<child[index].size();i++){
        DFS(child[index][i],depth+1);
    }
}
int main()
{
    int n;
    double p,r;
    cin >> n >> p >> r;
    r/=100;
    int father,root;
    for(int i=0;i<n;i++){
        cin >> father;
        if(father!=-1){
            child[father].push_back(i);
        }else{
            root=i;
        }
    }
    DFS(root,0);
    printf("%.2f %d",p*pow(1+r,maxDepth),num);
    return 0;
}