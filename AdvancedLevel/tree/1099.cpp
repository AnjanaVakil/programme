#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//和A1064很像
const int maxn=110;
int in[maxn],n;
struct node{
    int data;
    int left;
    int right;
}Node[maxn];
void levelorder(int root)
{
    queue<int> Q;
    Q.push(root);
    int num=0;
    while(!Q.empty()){
        int front=Q.front();
        cout << Node[front].data;
        num++;
        if(num<n) cout << " ";
        Q.pop();
        if(Node[front].left!=-1) Q.push(Node[front].left);
        if(Node[front].right!=-1) Q.push(Node[front].right);

    }
}
int num=0;
void inorder(int root)
{
    if(root==-1) return;
    inorder(Node[root].left);
    Node[root].data=in[num++];
    inorder(Node[root].right);
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
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    sort(in,in+n);//输入的in排序后就是in中序遍历的结果
    inorder(0);
    levelorder(0);
    return 0;
}