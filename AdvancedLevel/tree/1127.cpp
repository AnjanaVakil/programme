#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//45-08 30'
vector<int> in,post;
struct node{
    int val;
    node *left,*right;
};
node* create(int inL,int inR,int postL,int postR)
{
    if(postL>postR) return nullptr;
    node* root=new node();
    root->val=post[postR];
    int inK=inL;
    while(inK<=inR && in[inK]!=post[postR]) inK++;
    int numLeft=inK-inL;
    //注意，这里左子树是postL+numLeft-1 ，右子树才是postL+numLeft
    root->left=create(inL,inK-1,postL,postL+numLeft-1);
    root->right=create(inK+1,inR,postL+numLeft,postR-1);
    return root;
}
vector<int> ans;
int num=0;
void zigorder(node* root)
{
    queue<node*> q;
    q.push(root);
    int cnt=1;
    while(!q.empty()){
        vector<int> res;
        int size=q.size();
        for(int i=0;i<size;i++){
            node* cur=q.front();
            res.push_back(cur->val);
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        if(cnt%2==0){
            for(int i=0;i<res.size();i++){
                ans.push_back(res[i]);
            }
        }else{
            for(int i=res.size()-1;i>=0;i--){
                ans.push_back(res[i]);
            }
        }
        cnt++;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    in.reserve(n);
    post.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    node* root=create(0,n-1,0,n-1);
    zigorder(root);
    for(int i=0;i<ans.size();i++){
        if(i!=0) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}