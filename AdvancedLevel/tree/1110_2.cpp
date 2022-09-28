#include<iostream>
#include<queue>
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
int last;
bool bfs(int root)
{
    queue<int> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(cur==-1){
            break;
        }else{
            cnt++;
            last=cur;
            q.push(Node[cur].left);
            q.push(Node[cur].right);
        }
    }
    return cnt==n;
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
    if(bfs(root)){
        cout << "YES " << last << endl;
    }else{
        cout << "NO " << root << endl; 
    }
    return 0;
}