//40-03 25'
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int> node[maxn];
int n;
double p,r;
int minDepth=maxn,num=0;//num:minDepth的个数
void DFS(int index,int depth)
{
    if(node[index].size()==0){
        if(depth<minDepth){
            minDepth=depth;
            num=1;
        }else if(depth==minDepth){
            num++;
        }
        return;
    }
    for(int i=0;i<node[index].size();i++){
        DFS(node[index][i],depth+1);
    }
}
int main()
{
    cin >> n >> p >> r;
    r/=100;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(k!=0){
            int child;
            for(int j=0;j<k;j++){
                cin >> child;
                node[i].push_back(child);
            }
        }
    }
    DFS(0,0);
    printf("%.4f %d",p*pow(1+r,minDepth),num);
    return 0;
}