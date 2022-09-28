#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> Adj[maxn];
int n;
int indegree[maxn]={0};
int tempIndegree[maxn]={0};
bool isTopological(vector<int> order)
{
    for(int i=0;i<order.size();i++){
        int u=order[i];
        if(tempIndegree[u]!=0){
            return false;
        }else{
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j];
                tempIndegree[v]--;
            }
        }
    }
    return true;
}
int main()
{
    int m,k,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        indegree[b]++;
    }
    cin >> k;
    vector<int> res;
    for(int i=0;i<k;i++){
        //恢复原图的度数 下标是从1到n
        for(int j=1;j<=n;j++){
            tempIndegree[j]=indegree[j];
        }
        vector<int> order(n);
        for(int j=0;j<n;j++){
            cin >> order[j];
        }
        if(!isTopological(order)){
            res.push_back(i);
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i];
        if(i!=res.size()-1) cout << " ";
    }
    return 0;
}