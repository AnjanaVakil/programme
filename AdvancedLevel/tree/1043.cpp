#include<iostream>
#include<vector>
using namespace std;
//25'
const int maxn=1010;
struct node{
    int data;
    node* left;
    node* right;
};
int n;
vector<int> initial,pre,preMirror,post,postMirror;
//注意插入insert时参数root要加引用&
void insert(node* &root,int x)
{
    if(root==NULL){
        root=new node;
        //这个很重要，左右子树要初始化为nullptr
        //否则答案完全错误!
        root->data=x;
        root->left=root->right=NULL;
        return;
    }
    if(x<root->data) insert(root->left,x);
    else insert(root->right,x);
}
void preorder(node* root)
{
    if(root==NULL) return;
    pre.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}
void preorderMirror(node* root)
{
    if(root==NULL) return;
    preMirror.push_back(root->data);
    preorderMirror(root->right);
    preorderMirror(root->left);
}
void postorder(node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->data);
}
void postorderMirror(node* root)
{
    if(root==NULL) return;
    postorderMirror(root->right);
    postorderMirror(root->left);
    postMirror.push_back(root->data);
}
int main()
{
    cin >> n;
    node* root=NULL;
    int data;
    for(int i=0;i<n;i++){
        cin >> data;
        initial.push_back(data);
        insert(root,initial[i]);
    }
    preorder(root);
    preorderMirror(root);
    if(initial==pre){
        cout << "YES\n";
        postorder(root);
        for(int i=0;i<n;i++){
            cout << post[i];
            if(i!=n-1) cout << " ";
        }
    }else if(initial==preMirror){
        cout << "YES\n";
        postorderMirror(root);
        for(int i=0;i<n;i++){
            cout << postMirror[i];
            if(i!=n-1) cout << " ";
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}