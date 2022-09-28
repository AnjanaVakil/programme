#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//25'
//二叉树的静态实现
//push:preorder pop:inorder
vector<int> pre,in;
int n;
int num=0;
void post(int inL,int inR,int preL,int preR)
{
    if(preL>preR) return;
    int root_val=pre[preL];
    int inK=inL;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    post(inL,inK-1,preL+1,preL+numLeft);
    post(inK+1,inR,preL+numLeft+1,preR);
    //直接后序遍历输出
    cout << root_val;
    num++;
    if(num<n) cout << " ";
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
    post(0,n-1,0,n-1);
    return 0;
}