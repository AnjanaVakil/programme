#include<iostream>
#include<vector>
using namespace std;
//58-17 25‘
vector<int> in,pre;
int n;
struct node{
    int data;
    node* left;
    node* right;
};
node* create(int inL,int inR,int preL,int preR)
{
    if(preL>preR) return NULL;
    node* root=new node();
    root->data=pre[preL];
    int inK=inL;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    root->left=create(inL,inK-1,preL+1,preL+numLeft);
    root->right=create(inK+1,inR,preL+numLeft+1,preR);
    return root;
}
//使用flag
bool flag=false;
void postorder(node* root){
    if(flag==true) return;
    if(root){
        postorder(root->left);
        postorder(root->right);
        if(flag==false){
            printf("%d",root->data);
            flag=true;
        }
    }
}
int main()
{
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for(int i=0;i<n;i++){
        cin >> pre[i];
    }
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    node* root=create(0,n-1,0,n-1);
    postorder(root);
    return 0;
}