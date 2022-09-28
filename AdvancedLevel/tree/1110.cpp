#include<iostream>
using namespace std;
int n;
struct node{
    int left;
    int right;
}Node[25];
bool NotRoot[25]={false};
int findRoot()
{
    for(int i=0;i<n;i++){
        if(NotRoot[i]==false) return i;
    }
}
int maxn=-1,ans;
void dfs(int root,int index)
{
    if(index>maxn){
        maxn=index;
        ans=root;
    }
    if(Node[root].left!=-1) dfs(Node[root].left,2*index);
    if(Node[root].right!=-1) dfs(Node[root].right,2*index+1);
}
int main()
{
    cin >> n;
    string a,b;
    //结点的id可能是两位数，所以使用stoi,而不是char类型-'0'
    for(int i=0;i<n;i++){
        cin >> a  >> b;
        if(a!="-"){
            Node[i].left=stoi(a);
            NotRoot[stoi(a)]=true;
        }else{
            Node[i].left=-1;
        }
        if(b!="-"){
            Node[i].right=stoi(b);
            NotRoot[stoi(b)]=true;
        }else{
            Node[i].right=-1;
        }
    }
    int root=findRoot();
    // cout << root << endl;
    dfs(root,1);
    if(maxn==n){
        cout << "YES " << ans << endl;
    }else{
        cout << "NO " << root << endl;
    }
    return 0;
}