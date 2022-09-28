#include<iostream>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int N,M,a,b;
    cin >> N >> M;
    map<int,vector<int> > m;
    while(N--){
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    while(M--){
        int t,g[100005],flag=0;
        memset(g,0,sizeof(g));
        cin >> t;
        vector<int> v(t);
        for(int i=0;i<t;i++){
            cin >> v[i];
            g[v[i]]=1;
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<m[v[i]].size();j++){
                if(g[ m[v[i]][j]] ==1) flag=1;
            }
        }
        if(flag){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
    return 0;
}