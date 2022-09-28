#include<iostream>
#include<vector>
using namespace std;
const int maxn=10010;
int father[maxn];
int cnt[maxn]={0};
bool exist[maxn];
//并查集
//运行超时，需要路径压缩
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
    for(int i=1;i<=maxn;i++){
        father[i]=i;
    }
    int id,temp;
    for(int i=0;i<n;i++){
        cin >> k >> id;
        exist[id]=true;
        for(int j=1;j<k;j++){
            cin >> temp;
            exist[temp]=true;
            Union(id,temp);
        }
    }
    for(int i=1;i<=maxn;i++){
        if(exist[i]==true){
            int root=findFather(i);
            cnt[root]++;
        }
    }
    int tree=0,bird=0;
    for(int i=1;i<=maxn;i++){
        if(exist[i]==true && cnt[i]!=0){
            tree++;
            bird+=cnt[i];
        }
    }
    cout << tree << " " << bird << endl;
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