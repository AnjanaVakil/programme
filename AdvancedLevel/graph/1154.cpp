#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=10010;
struct node{
    int a,b;
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<node> v(m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&v[i].a,&v[i].b);
        // cin >> v[i].a >> v[i].b;
    }
    int k;
    cin >> k;
    while(k--){
        //重复时，初始化一定要放在循环里面，否则0'
        int color[maxn]={0};
        set<int> s;
        for(int j=0;j<n;j++){
            // scanf("%d",&color[j]);
            cin >> color[j];
            s.insert(color[j]);
        }
        bool flag=true;
        for(int j=0;j<m;j++){
            if(color[v[j].a]==color[v[j].b]){
                flag=false;
                break;
            }
        }
        if(flag){
            // printf("%d-coloring\n",s.size());
            cout << s.size() << "-coloring\n";
        }else{
            // printf("No\n");
            cout << "No\n";
        }
    }
    return 0;
}