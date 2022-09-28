//反转二叉树只需要进行后序遍历，在后序遍历访问根结点时交换left和right
#include<iostream>
#include<queue>
using namespace std;
//25'
const int maxn=110;
int n;
//二叉树的静态写法
struct node{
    int left;
    int right;
}Node[maxn];
bool notRoot[maxn]={false};
int num1=0;
void levelorder(int root)
{
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        printf("%d",front);
        num1++;
        if(num1<n) printf(" ");
        if(Node[front].left!=-1) Q.push(Node[front].left);
        if(Node[front].right!=-1) Q.push(Node[front].right);
    }
}
int num2=0;
void inorder(int root)
{
    if(root==-1) return;
    inorder(Node[root].left);
    printf("%d",root);
    num2++;
    if(num2<n) printf(" ");
    inorder(Node[root].right);
}
//后序遍历，用以反转二叉树
void postorder(int root)
{
    if(root==-1) return;
    postorder(Node[root].left);
    postorder(Node[root].right);
    swap(Node[root].left,Node[root].right);
}
int findRoot()
{
    for(int i=0;i<n;i++){
        if(notRoot[i]==false) return i;
    }
}
int main()
{
    // cin >> n;
    scanf("%d",&n);
    char a,b;
    for(int i=0;i<n;i++){
        // cin >> a >> b;
        //scanf的%c会读入换行符，所以需要用getchar()接收换行符
        //小技巧：用scanf("%*c")可以在scanf中接收一个字符
        scanf("%*c%c %c",&a,&b);
        if(isdigit(a)){
            Node[i].left=a-'0';
            notRoot[a-'0']=true;
        }else{
            Node[i].left=-1;
        }
        if(isdigit(b)){
            Node[i].right=b-'0';
            notRoot[b-'0']=true;
        }else{
            Node[i].right=-1;
        }
    }
    int root=findRoot();
    //根结点：不是任何结点的孩子 即：题目给出的所有左右孩子结点中没有出现过的结点，用bool型数组notRoot记录
    //reverse
    postorder(root);
    levelorder(root);
    printf("\n");
    inorder(root);
    return 0;
}