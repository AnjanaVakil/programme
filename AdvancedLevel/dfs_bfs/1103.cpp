#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
//30'
vector<int> ans,temp,facsum;
int maxsum=-1;
int n,k,p;
void init()
{
    int temp=0;
    for(int i=1;temp<=n;i++){
        facsum.push_back(temp);
        temp=pow(i,p);
    }
}
void dfs(int index,int tempres,int tempsum,int cnt)
{
    if(tempres==n && cnt==k){
        if(tempsum>maxsum){
            maxsum=tempsum;
            ans=temp;
        }
        return;
    }
    if(tempres>n || cnt>k) return;
    if(index>=1){
        temp.push_back(index);
        //选index
        dfs(index,tempres+facsum[index],tempsum+index,cnt+1);
        temp.pop_back();
        //不选index
        dfs(index-1,tempres,tempsum,cnt);
    }
    
}
int main()
{
    cin >> n >> k >> p;
    init();
    //index从大到小
    dfs(facsum.size()-1,0,0,0);
    if(maxsum==-1){
        printf("Impossible");
        return 0;
    }
    printf("%d =",n);
    for(int i=0;i<ans.size();i++){
        printf(" %d^%d",ans[i],p);
        if(i!=ans.size()-1) printf(" +");
    }
    return 0;
}