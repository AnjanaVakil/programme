#include<iostream>
#include<vector>
#include<map>
using namespace std;
int m,n,tol;
vector<vector<int> > v;
bool is_right(int i,int j)
{
    if(abs(v[i][j]-v[i-1][j-1])<=tol) return false;
    if(abs(v[i][j]-v[i-1][j])<=tol) return false;
    if(abs(v[i][j]-v[i-1][j+1])<=tol) return false;
    if(abs(v[i][j]-v[i][j-1])<=tol) return false;
    if(abs(v[i][j]-v[i][j+1])<=tol) return false;
    if(abs(v[i][j]-v[i+1][j-1])<=tol) return false;
    if(abs(v[i][j]-v[i+1][j])<=tol) return false;
    if(abs(v[i][j]-v[i+1][j+1])<=tol) return false;
    return true;
}
int main()
{
    int cnt=0,x,y;
    // cin >> m >> n >> tol;
    //运行超时，将cin改为scanf
    scanf("%d%d%d",&m,&n,&tol);
    //下标从1开始遍历的话，初始化为n+2和m+2，不是n和m
    //否则会有segmentation fault!!!
    v.resize(n+2,vector<int>(m+2));
    map<int,int> mapp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cin >> v[i][j];
            scanf("%d",&v[i][j]);
            mapp[v[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // if(is_right(v,i,j,tol) && mapp[v[i][j]]==1){
            //    cnt++;
            //    x=i;
            //    y=j;
            // }
            //将cin改为scanf还是会有运行超时问题
            //仔细分析这个判断，就会发现两个的位置很重要
            if(mapp[v[i][j]]==1 && is_right(i,j)){
                cnt++;
                x=i;
                y=j;
            }
           if(cnt==2) break;
        }
    }
    if(cnt==0){
        printf("Not Exist");
    }else if(cnt==1){
        printf("(%d, %d): %d",y,x,v[x][y]);
    }else{
        printf("Not Unique");
    }
    return 0;
}