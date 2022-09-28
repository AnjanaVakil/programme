#include<iostream>
#include<vector>
using namespace std;
vector<int> in,pre;
int n;
//直接后序遍历，不用构造树
bool flag=false;
void postorder(int inL,int inR,int preL,int preR)
{
    if(preL>preR || flag==true) return;
    int root_data=pre[preL];
    int inK=inL;
    while(inK<=inR && in[inK]!=pre[preL]) inK++;
    int numLeft=inK-inL;
    postorder(inL,inK-1,preL+1,preL+numLeft);
    postorder(inK+1,inR,preL+numLeft+1,preR);
    if(flag==false){
        printf("%d",root_data);
        flag=true;
    }
}

int main()
{
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for(int i=0;i<n;i++){
        cin >> pre[i];
    }
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    postorder(0,n-1,0,n-1);
    return 0;
}