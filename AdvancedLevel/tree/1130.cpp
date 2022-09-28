#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
    string val;
    int left,right;
};
vector<node> v;
int root=1;
string dfs(int index)
{
    if(index==-1) return "";
    if(v[index].right!=-1){
        v[index].val=dfs(v[index].left)+v[index].val+dfs(v[index].right);
        if(index!=root) v[index].val="("+v[index].val+")";
    }
    return v[index].val;
}
int main()
{
    int n;
    cin >> n;
    v.resize(n+1);
    map<int,bool> vis;
    for(int i=1;i<=n;i++){
        cin >> v[i].val >> v[i].left>> v[i].right;
        if(v[i].left!=-1) vis[v[i].left]=true;
        if(v[i].right!=-1) vis[v[i].right]=true;
    }
    //寻找根结点root
    while(vis[root]==true) root++;
    cout <<  dfs(root);
    return 0;
}