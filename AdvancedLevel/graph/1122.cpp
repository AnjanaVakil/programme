#include<iostream>
#include<vector>
#include<set>
using namespace std;
//22' 还要判断这条路能不能走通
vector<vector<int> > v;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    v.resize(n+1);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k,vnum;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
        scanf("%d",&vnum);
        int temp;
        vector<int> num(vnum);
        set<int> s;
        for(int i=0;i<vnum;i++){
            scanf("%d",&num[i]);
            s.insert(num[i]);
        }
        if(s.size()==n && vnum==n+1 && num[0]==num[vnum-1]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}