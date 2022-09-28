#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
//25'
const int maxn=1024;
struct node{
    int val,index,left,right,level;
}Node[maxn];
int book[maxn];
vector<node> in;
void inorder(int index,int root,int level)
{
    if(Node[root].right!=-1) inorder(index*2+2,Node[root].right,level+1);
    in.push_back({root,index,0,0,level});
    if(Node[root].left!=-1) inorder(index*2+1,Node[root].left,level+1);
}
bool cmp(node a,node b)
{
    if(a.level!=b.level) return a.level<b.level;
    return a.index>b.index;
}
int main()
{
    int n;
    cin >> n;
    string a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        Node[i].val=i;
        if(a!="-"){
            Node[i].left=stoi(a);
            book[stoi(a)]=1;
        }else{
            Node[i].left=-1;
        }
        if(b!="-"){
            Node[i].right=stoi(b);
            book[stoi(b)]=1;
        }else{
            Node[i].right=-1;
        }
    }
    int root;
    for(int i=0;i<n;i++){
        if(book[i]==0){
            root=i;
            break;
        }
    }
    inorder(0,root,0);
    vector<node> level(in);
    sort(level.begin(),level.end(),cmp);
    for(int i=0;i<level.size();i++){
        if(i!=0) cout << " ";
        cout << level[i].val;
    }
    cout << "\n";
    for(int i=0;i<in.size();i++){
        if(i!=0) cout << " ";
        cout << in[i].val;
    }
    return 0;
}