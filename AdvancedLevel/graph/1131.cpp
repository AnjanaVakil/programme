#include<iostream>
#include<vector>
#include<unordered_map>
//有问题
using namespace std;
const int maxn=10000;
vector<vector<int> > v(maxn);
bool vis[maxn]={false};
int minCnt,minTransfer,start,end1;
unordered_map<int,int> line;
vector<int> path,tempPath;
int transferCnt(vector<int> a)
{
    int cnt=-1,preLine=0;
    for(int i=1;i<a.size();i++){
        if(line[a[i-1]*maxn+a[i]]!=preLine) cnt++;
        preLine=line[a[i-1]*maxn+a[i]];
    }
    return cnt;
}
void dfs(int node,int cnt)
{
    if(node==end1 && (cnt<minCnt || (cnt==minCnt && transferCnt(tempPath)<minTransfer))){
        minCnt=cnt;
        minTransfer=transferCnt(tempPath);
        path=tempPath;
    }
    if(node==end1) return;
    for(int i=0;i<v[node].size();i++){
        int index=v[node][i];
        if(vis[index]==false){
            vis[index]=true;
            tempPath.push_back(index);
            dfs(index,cnt+1);
            vis[index]=false;
            tempPath.pop_back();
        }
    }
}
int main()
{
    int n,m,pre,temp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m >> pre;
        for(int j=1;j<m;j++){
            cin >> temp;
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*maxn+temp]=line[temp*maxn+pre]=i+1;
            pre=temp;
        }
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> start >> end1;
        minCnt=maxn,minTransfer=maxn;
        tempPath.clear();
        tempPath.push_back(start);
        vis[start]=true;
        dfs(start,0);
        vis[start]=false;
        cout << minCnt << "\n";
        int preLine=0,preTransfer=start;
        for(int j=1;j<path.size();j++){
            if(line[path[j-1]*maxn+path[j]]!=preLine){
                if(preLine!=0) printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,path[j-1]);
                preLine=line[path[j-1]*maxn+path[j]];
                preTransfer=path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",preLine,preTransfer,end1);
    }
    return 0;
}