#include<iostream>
#include<map>
using namespace std;
//30‘
const int maxn=2010;
int G[maxn][maxn],weight[maxn];
bool vis[maxn]={false};
map<string,int> stringToint;
map<int,string> intTostring;
//The output must be sorted according to the alphabetical order of the names of the heads.
//使用 map按照key自动从小到大排序
map<string,int> ans;
int idNumber=1;
int n,k;
int func(string s)
{
    if(stringToint[s]==0){
        stringToint[s]=idNumber;
        intTostring[idNumber]=s;
        return idNumber++;
    }else{
        return stringToint[s];
    }
}
//numMember一直忘记加 &了，如果一个错误一直找不出来就休息后面再看，否则花很长时间也找不出是哪错了
//写代码的过程专注，一遍就写好
void dfs(int u,int &totalWei,int &head,int &numMember)
{
    vis[u]=true;
    numMember++;
    if(weight[u]>weight[head]){
        head=u;
    }
    //是<idNumber
    for(int v=1;v<idNumber;v++){
        if(G[u][v]>0){
            totalWei+=G[u][v];
            //遍历过一条边之后就把这条边的权值设为0（ G[u][v] = G[v][u] = 0;）防止出现回路遍历死循环
            G[u][v]=G[v][u]=0;
            if(vis[v]==false){
                dfs(v,totalWei,head,numMember);
            }
        }
    }
}
void dfsTraversal()
{
    for(int u=1;u<idNumber;u++){
        if(vis[u]==false){
            int totalWei=0,head=u,numMember=0;
            dfs(u,totalWei,head,numMember);
            if(numMember>2 && totalWei>k){
                ans[intTostring[head]]=numMember;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    string a,b;
    int t;
    for(int i=0;i<n;i++){
        cin >> a >> b >> t;
        int t1=func(a);
        int t2=func(b);
        G[t1][t2]+=t;
        G[t2][t1]+=t;
        weight[t1]+=t;
        weight[t2]+=t;
    }
    dfsTraversal();
    cout << ans.size() << endl;
    for(auto it=ans.begin();it!=ans.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}