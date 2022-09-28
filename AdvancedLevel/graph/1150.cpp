#include<iostream>
#include<vector>
#include<climits>
//使用set,就不用一个个遍历，直接比较n和set的大小
#include<set>
using namespace std;
const int maxv=300;
int G[maxv][maxv];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int a,b,d;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&d);
        G[a][b]=G[b][a]=d;
    }
    int k,num;
    scanf("%d",&k);
    int index,minDis=INT_MAX;
    for(int i=1;i<=k;i++){
        scanf("%d",&num);
        vector<int> path(num+1);
        set<int> s;
        int dis=0,flag=1;
        scanf("%d",&path[1]);
        for(int j=2;j<=num;j++){
            scanf("%d",&path[j]);
            s.insert(path[j]); 
            if(G[path[j-1]][path[j]]==0) flag=0;
            dis+=G[path[j-1]][path[j]];
        }
        if(flag==0){
            printf("Path %d: NA (Not a TS cycle)\n",i);
        }else if(path[1]!=path[num] || s.size()!=n){
            printf("Path %d: %d (Not a TS cycle)\n",i,dis);
        }else if(num!=n+1){
            printf("Path %d: %d (TS cycle)\n",i,dis);
            if(dis<minDis){
                minDis=dis;
                index=i;
            }
        }else{
            printf("Path %d: %d (TS simple cycle)\n",i,dis);
            if(dis<minDis){
                minDis=dis;
                index=i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n",index,minDis);
    return 0;
}