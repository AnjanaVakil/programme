#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int N,M,a,b;
    //map建立的是 int 和 动态数组vector的map
    //存储一个物品的所有排斥物品，一个物品不一定仅仅只有一个排斥物品。
    map< int,vector<int> > m;
    cin >> N >> M;
    while(N--){
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    while(M--){
        int cnt,flag=0,a[100000]={0};
        cin >> cnt;
        vector<int> v(cnt);
        for(int i=0;i<cnt;i++){
            cin >> v[i];
            a[v[i]]=1;
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<m[v[i]].size();j++){
                if(a[ m[v[i]][j] ]==1) flag=1;
            }
        }
        printf("%s\n",flag?"No":"Yes");
    }
    return 0;
}