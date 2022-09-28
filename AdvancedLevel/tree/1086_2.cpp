#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//43-51 25'
//push:preorder pop:inorder
vector<int> pre,in;
int n;
struct node{
    int val;
    node *left,*right;
};
node* build(int inL,int inR,int preL,int preR)
{
    if(preL>preR) return nullptr;
    node *root=new node();
    root->val=pre[preL];
    int inK=inL;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    root->left=build(inL,inK-1,preL+1,preL+numLeft);
    root->right=build(inK+1,inR,preL+numLeft+1,preR);
    return root;
}
int num=0;
void postorder(node* root)
{
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->val;
        num++;
        if(num<n) cout << " ";
    }
}
int main()
{
    cin >> n;
    pre.resize(n);
    in.resize(n);
    string s;
    int t;
    stack<int> stk;
    int cnt1=0,cnt2=0;
    for(int i=0;i<2*n;i++){
        cin >> s;
        if(s=="Push"){
            cin >> t;
            pre[cnt1++]=t;
            stk.push(t);
        }else{
            in[cnt2++]=stk.top();
            stk.pop();
        }
    }
    node* root=build(0,n-1,0,n-1);
    postorder(root);
    return 0;
}