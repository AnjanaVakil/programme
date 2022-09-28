#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//25'
const int maxn=100010;
vector<int> v[maxn];
int num,minDepth=maxn;
void dfs(int index,int depth)
{
    if(v[index].size()==0){
        if(depth<minDepth){
            minDepth=depth;
            num=1;
        }else if(depth==minDepth){
            num++;
        }
        return;
    }
    for(int i=0;i<v[index].size();i++){
        dfs(v[index][i],depth+1);
    }
}
int main()
{
    int n,k;
    double p,r;
    cin >> n >> p >> r;
    r/=100;
    for(int i=0;i<n;i++){
        cin >> k;
        if(k!=0){
            int temp;
            for(int j=0;j<k;j++){
                cin >> temp;
                v[i].push_back(temp);
            }
        }
    }
    dfs(0,0);
    printf("%.4f %d",p*pow(1+r,minDepth),num);
    return 0;
}