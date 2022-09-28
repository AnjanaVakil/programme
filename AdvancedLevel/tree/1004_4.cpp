#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//30'
const int maxn=110;
vector<int> v[maxn];
int leave[maxn],maxdepth=-1;
void dfs(int index,int depth)
{
    if(v[index].size()==0){
        leave[depth]++;
        maxdepth=max(depth,maxdepth);
        return;
    } 
    for(int i=0;i<v[index].size();i++){
        dfs(v[index][i],depth+1);
    }
}
int main()
{
    int n,m,id,k;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> id >> k;
        int ids;
        for(int j=0;j<k;j++){
            cin >> ids;
            v[id].push_back(ids);
        }
    }
    dfs(1,1);
    for(int i=1;i<=maxdepth;i++){
        cout << leave[i];
        if(i!=maxdepth) cout << " ";
    }
    return 0;
}