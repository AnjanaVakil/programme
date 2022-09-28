#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//segmentation fault
struct node{
    int data;
    node* left;
    node* right;
};
int getHeight(node* root)
{
    if(root==NULL) return 0;
    return max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalanceFactor(node* root)
{
    return getHeight(root->left)-getHeight(root->right);
}
node* leftRotate(node* root)
{
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}
node* rightRotate(node* root)
{
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}
node* leftRightRotate(node* root)
{
    root->left=leftRotate(root->left);
    return rightRotate(root);
}
node* rightLeftRotate(node* root)
{
    root->right=rightRotate(root->right);
    return leftRotate(root);
}
node* insert(node* root,int x)
{
    if(root==NULL){
        root=new node;
        root->data=x;
    }
    if(x<root->data){
        root->left=insert(root->left,x);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(l-r>=2){
            if(x<root->left->data){
                root=rightRotate(root);
            }else{
                root=leftRightRotate(root);
            }
        }
    }
    else{
        root->right=insert(root->right,x);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(r-l>=2){
            if(x>root->right->data){
                root=leftRotate(root);
            }else{
                root=rightLeftRotate(root);
            }
        }
    } 
    return root;
}
int n;
int num=0;
bool isComplete=true,after=false;
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    bool isLeaf=false;
    while(!q.empty()){
        node* node=q.front();
        q.pop();
        printf("%d",node->data);
        num++;
        if(num<n) printf(" ");
        if(node->left){
            if(after) isComplete=false;
            q.push(node->left);
        }else{
            after=true;
        }
        if(node->right){
            if(after) isComplete=false;
            q.push(node->right);
        }else{
            after=true;
        }
    }
}
int main()
{
    cin >> n;
    int num;
    node* root=nullptr;
    for(int i=0;i<n;i++){
        cin >> num;
        root=insert(root,num);
    }
    levelorder(root);
    printf("\n%s",isComplete?"YES":"NO");
    //判断是不是完全二叉树，就看在出现了一个孩子为空的结点之后是否还会出现孩子结点不为空的结点，如果出现了就不是完全二叉树。
    return 0;
}