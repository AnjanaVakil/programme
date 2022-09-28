#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//30'
unordered_map<int,int> pos;
vector<int> in,pre;
struct node{
    int data;
    node* left;
    node* right;
};
node* create(int preL,int preR,int inL,int inR)
{
    if(preL>preR) return NULL;
    node* root=new node();
    root->data=pre[preL];
    int inK;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    root->left=create(preL+1,preL+numLeft,inL,inK-1);
    root->right=create(preL+numLeft+1,preR,inK+1,inR);
    return root;
}
void LCA(node* root,int u,int v)
{
    int inRoot=pos[root->data];
    int uin=pos[u],vin=pos[v];
    if(uin<inRoot && vin<inRoot){
        LCA(root->left,u,v);
    }else if((uin>inRoot && vin<inRoot) || (uin<inRoot && vin>inRoot)){
        printf("LCA of %d and %d is %d.\n",u,v,in[inRoot]);
    }else if(uin>inRoot && vin>inRoot){
        LCA(root->right,u,v);
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
    node* root=create(1,n,1,n);
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
            LCA(root,u,v);
        }
    }
    return 0;
}