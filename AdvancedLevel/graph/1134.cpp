#include<iostream>
#include<vector>
using namespace std;
//56- 没理解题意,不会写
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    vector<int> v[n];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    int k,vnum;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&vnum);
        int num;
        vector<int> exist(m,0);
        for(int j=0;j<vnum;j++){
            scanf("%d",&num);
            for(int k=0;k<v[num].size();k++){
                exist[v[num][k]]=1;
            }
        }
        int flag=1;
        for(int j=0;j<m;j++){
            if(exist[j]==0) {
                printf("No\n");
                flag=0;
                break;
            }
        }
        if(flag) printf("Yes\n"); 
    }
    return 0;
}