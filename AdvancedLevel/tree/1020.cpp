//postorder+inorder---->levelorder
#include<iostream>
#include<queue>
using namespace std;
const int maxn=35;
struct node{
    int data;
    node* left;
    node* right;
};
int postorder[maxn],inorder[maxn];
int n;
node* create(int postL,int postR,int inL,int inR)
{
    if(postL>postR) return NULL;
    node* root=new node;
    root->data=postorder[postR];
    int inK;
    for(inK=inL;inK<=inR;inK++){
        if(inorder[inK]==postorder[postR]){
            break;
        }
    }
    int numLeft=inK-inL;
    root->left=create(postL,postL+numLeft-1,inL,inK-1);
    root->right=create(postL+numLeft,postR-1,inK+1,inR);
    return root;
}
int num=0;//已输出的结点个数，控制序列中空格的输出
//levelorder
void BFS(node* root){
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node* front=Q.front();
        Q.pop();
        cout << front->data;
        num++;
        if(num<n) cout << " ";
        if(front->left!=NULL) Q.push(front->left);
        if(front->right!=NULL) Q.push(front->right);
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> postorder[i];
    }
    for(int i=0;i<n;i++){
        cin >> inorder[i];
    }
    node* root=create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}