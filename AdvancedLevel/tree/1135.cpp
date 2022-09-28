#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
struct node{
    int val;
    node *left,*right;
};
//red-black tree 也是BST binary search treee
node* build(node* root,int val)
{
    if(root==nullptr){
        root=new node();
        root->val=val;
        root->left=root->right=nullptr;
    }else if(abs(val)<=abs(root->val)){
        root->left=build(root->left,val);
    }else{
        root->right=build(root->right,val);
    }
    return root;
}
//if a node is red,then both its children are black
bool judge1(node* root)
{
    if(root==nullptr) return true;
    if(root->val<0){
        if(root->left!=nullptr && root->left->val<0) return false;
        if(root->right!=nullptr && root->right->val<0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
//统计black结点的个数
int getNumB(node* root)
{
    if(root==nullptr) return 0;
    int l=getNumB(root->left);
    int r=getNumB(root->right);
    return root->val>0 ? max(l,r)+1:max(l,r);
}
//For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
bool judge2(node* root)
{
    if(root==nullptr) return true;
    int l=getNumB(root->left);
    int r=getNumB(root->right);
    if(l!=r) return false;
    return judge2(root->left) && judge2(root->right);
}
int main()
{
    int k,n;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> n;
        v.resize(n);
        int num;
        node* root=nullptr;
        for(int j=0;j<n;j++){
            cin >> v[j];
            root=build(root,v[j]);
        }
        if(v[0]<0 || judge1(root)==false || judge2(root)==false){
            cout << "No\n";
        }else {
            cout << "Yes\n";
        }
    }
    return 0;
}