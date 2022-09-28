#include<iostream>
#include<algorithm>
using namespace std;
//和A1099很像
//要构建的是完全二叉排序树
//可以利用左孩子结点编号2*x,右孩子结点编号2*x+1
const int maxn=1010;
int n,CBT[maxn],origin[maxn],index=0;
void inorder(int root)
{
    if(root>n) return;
    inorder(root*2);
    CBT[root]=origin[index++];
    inorder(root*2+1); 
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> origin[i];
    }
    sort(origin,origin+n);
    inorder(1);
    for(int i=1;i<=n;i++){
        cout << CBT[i];
        if(i!=n) cout << " "; 
    }
    return 0;
}