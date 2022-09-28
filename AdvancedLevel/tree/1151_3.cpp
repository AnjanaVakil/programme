#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,int> pos;
vector<int> in,pre;
//30'
void LCA(int preL,int preR,int inL,int inR,int u,int v)
{
    if(inL>inR) return;
    int inRoot=pos[pre[preL]];
    int uin=pos[u],vin=pos[v];
    int numLeft=inRoot-inL;
    if(uin<inRoot && vin<inRoot){
        LCA(preL+1,preL+numLeft,inL,inRoot-1,u,v);
    }else if((uin>inRoot && vin<inRoot) || (uin<inRoot && vin>inRoot)){
        printf("LCA of %d and %d is %d.\n",u,v,in[inRoot]);
    }else if(uin>inRoot && vin>inRoot){
        LCA(preL+numLeft+1,preR,inRoot+1,inR,u,v);
    }else if(uin==inRoot){
        printf("%d is an ancestor of %d.\n",u,v);
    }else if(vin==inRoot){
        printf("%d is an ancestor of %d.\n",v,u);
    }
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    in.resize(n+1);
    pre.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&in[i]);
        pos[in[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
    }
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        if(pos[u]==0 && pos[v]==0){
            printf("ERROR: %d and %d are not found.\n",u,v);
        }else if(pos[u]==0){
            printf("ERROR: %d is not found.\n",u);
        }else if(pos[v]==0){
            printf("ERROR: %d is not found.\n",v);
        }else{
            LCA(1,n,1,n,u,v);
        }
    }
    return 0;
}