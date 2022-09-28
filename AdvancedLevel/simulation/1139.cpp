#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int maxn=10000;
unordered_map<int,bool> arr;
struct node{
    int a,b;
};
bool cmp(node x,node y)
{
    return x.a!=y.a?x.a<y.a:x.b<y.b;
}
int main()
{
    int n,m;
    cin >> n >> m;
    string a,b;
    vector<int> v[maxn];
    for(int i=0;i<m;i++){
        cin >> a >> b;
        int x=abs(stoi(a));
        int y=abs(stoi(b));
        if(a.length()==b.length()){
            v[x].push_back(y);
            v[y].push_back(x);
        }
        arr[x*maxn+y]=arr[y*maxn+x]=true;
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int c,d;
        cin >> c >> d;
        vector<node> res;
        for(int j=0;j<v[abs(c)].size();j++){
            for(int k=0;k<v[abs(d)].size();k++){
                if(v[abs(c)][j]==abs(d) || abs(c)==v[abs(d)][k]){
                    continue;
                }
                if(arr[v[abs(c)][j]*maxn+v[abs(d)][k]]==true){
                    res.push_back(node{v[abs(c)][j],v[abs(d)][k]});
                }
            }
        }
        sort(res.begin(),res.end(),cmp);
        printf("%d\n",res.size());
        for(int j=0;j<res.size();j++){
            printf("%04d %04d\n",res[j].a,res[j].b);
        }
    }
    return 0;
}