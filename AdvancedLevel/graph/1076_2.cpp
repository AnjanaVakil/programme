#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//30'
const int maxn=1010;
struct node{
    int id,layer;
};
vector<int> v[maxn];
int n,l,m;
int bfs(node tnode)
{
    //inq每次都需要初始化为false
    bool inq[maxn]={false};
    //queue的数据类型必须为node
    queue<node> q;
    q.push(tnode);
    inq[tnode.id]=true;
    int cnt=0;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        int u=cur.id;
        for(int i=0;i<v[u].size();i++){
            int child=v[u][i];
            if(inq[child]==false && cur.layer<l){
                node next={child,cur.layer+1};
                q.push(next);
                inq[child]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> l;
    for(int i=1;i<=n;i++){
        cin >> m;
        int temp;
        for(int j=0;j<m;j++){
            cin >> temp;
            v[temp].push_back(i);
        }
    }
    int k,query;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> query;
        node temp={query,0};
        cout << bfs(temp) << endl;
    }
    return 0;
}