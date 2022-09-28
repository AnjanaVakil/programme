#include<iostream>
#include<vector>
#include<queue>
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
        insert(root,num);
    }
    levelorder(root);
    printf("\n%s",isComplete?"YES":"NO");
    //判断是不是完全二叉树，就看在出现了一个孩子为空的结点之后是否还会出现孩子结点不为空的结点，如果出现了就不是完全二叉树。
    return 0;
}