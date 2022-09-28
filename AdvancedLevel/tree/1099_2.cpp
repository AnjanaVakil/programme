#include<iostream>
#include<cctype>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
//30'
const int maxn=110;
struct node{
    int val,left,right;
}Node[maxn];
vector<int> in,level;
int n;
int ind=0;
void inorder(int root)
{
    //这里的递归边界是root==-1
    if(root==-1) return;
    inorder(Node[root].left);
    Node[root].val=in[ind++];
    inorder(Node[root].right);
}
int num=0;
void levelorder(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout << Node[front].val;
        num++; 
        if(num<n) cout << " ";
        if(Node[front].left!=-1) q.push(Node[front].left);
        if(Node[front].right!=-1) q.push(Node[front].right);
    }
}
int main()
{
    cin >> n;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        Node[i].left=a;
        Node[i].right=b;
    }
    in.resize(n);
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    sort(in.begin(),in.end());
    inorder(0);
    levelorder(0);
    return 0;
}