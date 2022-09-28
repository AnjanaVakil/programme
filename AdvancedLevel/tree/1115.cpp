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
    }else{
        //这边一直忘了root->left=insert(xx) root->right=insert(xx)
        //难怪一直segmentation fault段错误
        if(val<=root->val) root->left=insert(root->left,val);
        else if(val>root->val) root->right=insert(root->right,val);
    }
    return root;
}
vector<int> res;
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        res.push_back(size);
        for(int i=0;i<size;i++){
            node* cur=q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
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
    levelorder(root);
    int size=res.size();
    int n1=res[size-1],n2=res[size-2];
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}