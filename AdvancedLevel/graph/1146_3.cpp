#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> Adj[maxn];
int n;
int indegree[maxn]={0};
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
    int flag=0;
    for(int i=0;i<k;i++){
        int judge=1;
        //恢复原图的度数!!!
        //使用vector<int>的构造函数复制
        vector<int> tempIndegree(indegree,indegree+n+1);
        int index;
        for(int j=0;j<n;j++){
            cin >> index;
            if(tempIndegree[index]!=0) judge=0;
            for(int it:Adj[index]) tempIndegree[it]--;
        }
        if(judge==1) continue;
        if(flag==1) cout << " ";
        cout << i;
        flag=1;
    }
    return 0;
}