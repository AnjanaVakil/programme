#include<iostream>
#include<vector>
#include<map>
using namespace std;
//使用二叉树的静态实现:数组
vector<int> post,in;
//map的排序默认按照key从小到大进行排序
//层序遍历使用map,map会按照index从小到大自动排序
map<int,int> level; 
int n;
void pre(int inL,int inR,int postL,int postR,int index)
{
    if(postL>postR) return;
    level[index]=post[postR];
    int inK=inL;
    while(inK<=inR && in[inK]!=post[postR]) inK++;
    int numLeft=inK-inL;
    pre(inL,inK-1,postL,postL+numLeft-1,index*2+1);
    pre(inK+1,inR,postL+numLeft,postR-1,index*2+2);
}
int main()
{
    cin >> n;
    post.resize(n);
    in.resize(n);
    for(int i=0;i<n;i++){
        cin >> post[i];
    }
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    pre(0,n-1,0,n-1,0);
    auto it=level.begin();
    cout << it->second;
    while(++it !=level.end()){
        cout << " " << it->second;
    }
    return 0;
}