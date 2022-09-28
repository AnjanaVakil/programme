#include<iostream>
#include<vector>
using namespace std;
bool uni=true;
vector<int> pre,post,in;
int n;
struct node{
    int data;
    node* left;
    node* right;
};
node* create(int preL,int preR,int postL,int postR)
{
    if(preL>preR) return NULL;
    node* root=new node();
    root->data=pre[preL];
    if(preL==preR) return root;
    int i=preL+1;
    while(i<=preR && pre[i]!=post[postR-1]) i++;
    int numLeft=i-(preL+1);
    if(numLeft>0){
        root->left=create(preL+1,i-1,postL,postL+numLeft-1);
    }else{
        uni=false;
    }
    root->right=create(i,preR,postL+numLeft,postR-1);
    return root;
}
int num=0;
void inorder(node* root){
    if(root){
        inorder(root->left);
        printf("%d",root->data);
        num++;
        if(num<n) printf(" ");
        inorder(root->right);
    }
}
int main()
{
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++){
        cin >> pre[i];
    }
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    node* root=create(0,n-1,0,n-1);
    if(uni){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    inorder(root);
    cout << endl;
    return 0;
}