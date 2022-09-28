#include<iostream>
#include<vector>
#include<set>
using namespace std;
//25'
const int maxv=210;
int G[maxv][maxv]={0};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        G[a][b]=G[b][a]=1;
    }
    int k,vnum;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
        scanf("%d",&vnum);
        int temp;
        vector<int> num(vnum);
        set<int> s;
        int flag=1;
        scanf("%d",&num[0]);
        for(int i=1;i<vnum;i++){
            scanf("%d",&num[i]);
            if(G[num[i]][num[i-1]]==0) flag=0;
            s.insert(num[i]);
        }
        if(s.size()==n && vnum==n+1 && num[0]==num[vnum-1] && flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}