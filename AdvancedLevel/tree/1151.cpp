#include<iostream>
#include<vector>
#include<map>
using namespace std;
//30'
map<int,int> pos;
vector<int> in,pre;
void LCA(int inL,int inR,int preRoot,int a,int b)
{
    if(inL>inR) return;
    int inRoot=pos[pre[preRoot]],ain=pos[a],bin=pos[b];
    if(ain<inRoot && bin<inRoot){ 
        LCA(inL,inRoot-1,preRoot+1,a,b);
    }
    else if((ain>inRoot && bin<inRoot) || (ain<inRoot && bin>inRoot)){
        printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
    }else if(ain>inRoot && bin>inRoot){
        LCA(inRoot+1,inR,preRoot+1+(inRoot-inL),a,b);
    }else if(ain==inRoot){
        printf("%d is an ancestor of %d.\n",a,b);
    }else if(bin==inRoot){
        printf("%d is an ancestor of %d.\n",b,a);
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
            LCA(1,n,1,u,v);
        }
    }
    return 0;
}