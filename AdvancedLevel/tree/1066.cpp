#include<iostream>
using namespace std;
struct node{
    int data,height;
    node* left;
    node* right;
};
int getHeight(node* root)
{
    if(root==NULL) return 0;
    return root->height;
}
int getBalanceFactor(node* root)
{
    return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(node* root)
{
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
//左旋
void L(node* &root)
{
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root); //一定要先更新下层结点再更新上层结点
    updateHeight(temp);
    root=temp;
}
void R(node* &root)
{
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void insert(node* &root,int x)
{
    if(root==NULL){
        root=new node;
        root->data=x;
        root->height=1;
        root->left=root->right=NULL;
        return;
    }
    if(x<root->data){
        insert(root->left,x);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1){
                //LL
                R(root);
            }else if(getBalanceFactor(root->left)==-1){
                //LR
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right,x);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->right)==-1){
                //RR
                L(root);
            }else if(getBalanceFactor(root->right)==1){
                //Rl
                R(root->right);
                L(root);
            }
        }
    } 
}
int main()
{
    int n;
    cin >> n;
    int data;
    node* root=NULL;
    for(int i=0;i<n;i++){
        cin >> data;
        insert(root,data);
    }
    cout << root->data;
    return 0;
}