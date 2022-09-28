#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
//30'
int n,p,k,maxFacSum=-1;
vector<int> temp,ans,fac;
void init()
{
    int i=0,temp=0;
    while(temp<=n){
        fac.push_back(temp);
        temp=pow(++i,p);
    }
}
void DFS(int index,int nowK,int sum,int facSum)
{
    if(nowK==k && sum==n){
        if(facSum>maxFacSum){
            maxFacSum=facSum;
            ans=temp;
        }
        return;
    }
    if(nowK>k || sum>n) return;
    //从v[i]的最后一个index开始一直到index == 1，因为这样才能保证ans和tempAns数组里面保存的是从大到小的因子的顺序
    if(index>=1){
        //选index
        temp.push_back(index);
        //sum数之和，加事先保存的fac[index]
        //facSum 底数之和，需要它是所有可能的结果中最大的
        DFS(index,nowK+1,sum+fac[index],facSum+index);
        //不选index
        temp.pop_back();
        DFS(index-1,nowK,sum,facSum);
    }
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    init();
    DFS(fac.size()-1,0,0,0);
    //一开始maxFacSum == -1，如果dfs后maxFacSum并没有被更新，还是-1，那么就输出Impossible
    if(maxFacSum==-1){
        printf("Impossible");
    }else{
        printf("%d = %d^%d",n,ans[0],p);
        for(int i=1;i<ans.size();i++){
            printf(" + %d^%d",ans[i],p);
        }
    }
    return 0;
}