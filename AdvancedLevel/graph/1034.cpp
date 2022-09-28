#include<iostream>
#include<map>
using namespace std;
const int maxn=2010;
int G[maxn][maxn],weight[maxn];
bool vis[maxn]={false};
map<string,int> stringToInt;
map<int,string> intToString;
map<string,int> ans;
//找到每个连通块的结点个数>2 && 权重和>k
int n,k,idNumber=1;
int stoifunc(string s)
{
    if(stringToInt[s]==0){
        stringToInt[s]=idNumber;
        intToString[idNumber]=s;
        return idNumber++;
    }else{
        return stringToInt[s];
    }
}
//DFS 访问单个连通块
//numMember 成员编号
void DFS(int u,int &head,int &numMember,int &totalWeight)
{
    vis[u]=true;
    numMember++;
    if(weight[u]>weight[head]){
        head=u;
    }
    for(int v=1;v<idNumber;v++){
        if(G[u][v]>0){
            totalWeight+=G[u][v];
            //防止出现回路遍历死循环
            G[u][v]=G[v][u]=0;
            if(vis[v]==false){
                DFS(v,head,numMember,totalWeight);
            }
        }
    }
}
void DFSTraversal()
{
    for(int i=1;i<idNumber;i++){
        if(vis[i]==false){
            int head=i,numMember=0,totalweight=0;
            DFS(i,head,numMember,totalweight);
            if(totalweight>k && numMember>2){
                ans[intToString[head]]=numMember;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    string a,b;
    int w;
    for(int i=0;i<n;i++){
        cin >> a >> b >> w;
        int id1=stoifunc(a);
        int id2=stoifunc(b);
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2]+=w;
        G[id2][id1]+=w;
    }
    DFSTraversal();
    cout << ans.size() << "\n";
    for(map<string,int>::iterator it=ans.begin();it!=ans.end();it++){
        cout << it->first << " " << it->second << "\n";
    }
    return 0;
}