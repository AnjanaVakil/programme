#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn=10010;
int father[maxn];
bool isRoot[maxn];
//并查集
//25'
int findFather(int x)
{
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void Union(int a,int b)
{
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}
int main()
{
    int n,k;
    cin >> n;
    set<int> s;
    for(int i=1;i<=maxn;i++){
        father[i]=i;
        isRoot[i]=false;
    }
    int id,temp;
    for(int i=0;i<n;i++){
        cin >> k >> id;
        s.insert(id);
        for(int j=1;j<k;j++){
            cin >> temp;
            s.insert(temp);
            Union(id,temp);
        }
    }
    for(auto it=s.begin();it!=s.end();it++){
        isRoot[findFather(*it)]=true;
    }
    int tree=0;
    for(int i=1;i<=maxn;i++){
        tree+=isRoot[i];
    }
    cout << tree << " " << s.size() << endl;
    int q,a,b;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> a >> b;
        if(findFather(a)==findFather(b)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}