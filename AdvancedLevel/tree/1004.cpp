#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];
// 标记第depth层拥有的叶子结点数
int book[100],maxdepth=-1;
void dfs(int index,int depth)
{
    if(v[index].size()==0){
        book[depth]++;
        maxdepth=max(maxdepth,depth);
        return ;
    }
    for(int i=0;i<v[index].size();i++){
        dfs(v[index][i],depth+1);
    }
}
int main()
{
    int n,m,id,k,idi;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> id >> k;
        for(int j=0;j<k;j++){
            cin >> idi;
            v[id].push_back(idi);
        }
    }
    dfs(1,0);
    cout << book[0];
    for(int i=1;i<=maxdepth;i++){
        cout << " " << book[i];
    }
    return 0;
}