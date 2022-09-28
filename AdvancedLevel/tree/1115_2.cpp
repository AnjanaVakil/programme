#include<iostream>
#include<queue>
using namespace std;
struct node{
    int val;
    node *left,*right;
};
node* insert(node* root,int val)
{
    if(root==nullptr){
        root=new node();
        root->val=val;
        root->left=root->right=nullptr;
    }else if(val<=root->val){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
vector<int> res(1100);
int maxdepth=-1;
void dfs(node* root,int depth)
{
    if(root==nullptr){
        maxdepth=max(depth,maxdepth);
        return;
    }
    res[depth]++;
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);
}
int main()
{
    int n;
    cin >> n;
    int num;
    node* root=nullptr;
    for(int i=0;i<n;i++){
        cin >> num;
        root=insert(root,num);
    }
    dfs(root,0);
    int n1=res[maxdepth-1],n2=res[maxdepth-2];
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}