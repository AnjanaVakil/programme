#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//30‘
int m,n;
vector<int> pre,in;
unordered_map<int,bool> mp;
struct node{
    int val;
    node *left,*right;
};
//BST pre+in
node* create(int preL,int preR,int inL,int inR)
{
    if(preL>preR) return nullptr; 
    node* root=new node();
    root->val=pre[preL];  
    int inK=inL;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    root->left=create(preL+1,preL+numLeft,inL,inK-1);
    root->right=create(preL+numLeft+1,preR,inK+1,inR);
    return root;
}
node* LCA(node* root,int u,int v)
{
    node* ancestor=root;
    while(ancestor){
        if(ancestor->val>u && ancestor->val>v){
            ancestor=ancestor->left;
        }else if(ancestor->val<u && ancestor->val<v){
            ancestor=ancestor->right;
        }else{
            break;
        }
    }
    return ancestor;
}
int main()
{
    scanf("%d %d", &m, &n);
    pre.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d", &pre[i]);
        mp[pre[i]]=true;
    }
    in=pre;
    sort(in.begin(),in.end());
    node* root=create(0,n-1,0,n-1);
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        if(mp[u]==false && mp[v]==false){
            printf("ERROR: %d and %d are not found.\n",u,v);
        }else if(mp[u]==false || mp[v]==false){
            printf("ERROR: %d is not found.\n",mp[u]==false?u:v);
        }else{
            node* ancestor=LCA(root,u,v);
            if(u==ancestor->val){
                printf("%d is an ancestor of %d.\n",u,v);
            }else if(v==ancestor->val){
                printf("%d is an ancestor of %d.\n",v,u);
            }else{
                printf("LCA of %d and %d is %d.\n",u,v,ancestor->val);
            }
        }
    }
    return 0;
}