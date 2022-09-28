#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
//forward 转发 
const int maxn=1010;
struct node{
    int id;
    int layer;
};
vector<node> Adj[maxn];
bool inq[maxn]={false};
int n,L;
//s起始顶点  L层数上限
int BFS(int s)
{
    int numForward=0;
    queue<node> q;
    node start;
    start.id=s;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;
    while(!q.empty()){
        node topNode=q.front();
        q.pop();
        int u=topNode.id;
        for(int i=0;i<Adj[u].size();i++){
            node next=Adj[u][i];
            next.layer=topNode.layer+1;
            if(inq[next.id]==false && next.layer<=L){
                q.push(next);
                inq[next.id]=true;
                numForward++;
            }
        }
    }
    return numForward;
}
int main()
{
    //L,the number of levels of indirect followers that are counted;
    cin >> n >> L;
    int k;
    node user;
    for(int i=1;i<=n;i++){
        user.id=i;
        cin >> k;
        int idFollow;
        for(int j=0;j<k;j++){
            cin >> idFollow;
            Adj[idFollow].push_back(user);
        }
    }
    int m,query;
    cin >> m;
    for(int i=0;i<m;i++){
        memset(inq,false,sizeof(inq));
        cin >> query;
        int numForward=BFS(query);
        cout << numForward << "\n";
    }
    return 0;
}