#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//00-17 25'
vector<int> post,in;
int n;
struct node{
    int val;
    node *left,*right;
};
node* build(int inL,int inR,int postL,int postR)
{
    if(postL>postR) return nullptr;
    node *root=new node();
    root->val=post[postR];
    int inK=inL;
    while(inK<=inR && in[inK]!=post[postR]) inK++;
    int numLeft=inK-inL;
    root->left=build(inL,inK-1,postL,postL+numLeft-1);
    root->right=build(inK+1,inR,postL+numLeft,postR-1);
    return root;
}
int num=0;
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *cur=q.front();
        q.pop();
        num++;
        if(num!=1){
            cout << " ";
        }
        cout << cur->val;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}
int main()
{
    cin >> n;
    post.resize(n);
    in.resize(n);
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    node* root=build(0,n-1,0,n-1);
    levelorder(root);
    return 0;
}