//02-23 25'
//preorder+inorder---->postorder
#include<iostream>
#include<stack>
using namespace std;
const int maxn=50;
int pre[maxn],in[maxn];
int n;
struct node{
    int data;
    node* left;
    node* right;
};
node* create(int preL,int preR,int inL,int inR)
{
    if(preL>preR) return NULL;
    node* root=new node();
    root->data=pre[preL];
    int inK;
    for(inK=inL;inK<=inR;inK++){
        if(in[inK]==pre[preL]){
            break;
        }
    }
    int numLeft=inK-inL;
    root->left=create(preL+1,preL+numLeft,inL,inK-1);
    root->right=create(preL+numLeft+1,preR,inK+1,inR);
    return root;
}
int num=0;
void postorder(node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    num++;
    if(num<n) printf(" ");
}
int main()
{
    cin >> n;
    string s;
    int num;
    stack<int> sta;
    int a=0,b=0;
    for(int i=0;i<2*n;i++){
        cin >> s;
        //push的次序 先序遍历 preorder
        //pop的次序 中序遍历 inorder
        if(s=="Push"){
            cin >> num;
            sta.push(num);
            pre[a++]=num;
        }else if(s=="Pop"){
            if(!sta.empty()){
                in[b++]=sta.top();
                sta.pop();
            }
        } 
    }
    node* root=create(0,n-1,0,n-1);
    postorder(root);
    return 0;
}