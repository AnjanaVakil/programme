#include<iostream>
#include<vector>
#include<set>
using namespace std;
// struct node{
//     string id;
//     int father,mother;
//     int child;
// };
//并查集 又是自己没写出来，要动脑筋才会有进步啊
const int maxn=5000;
int father[maxn];
bool isRoot[maxn];
int findFather(int x)
{
    while(x!=father[x]){
        x=father[x];
    }
    return x;
}
void Union(int a,int b)
{
    int fa=findFather(a);
    int fb=findFather(b);
    // if(fa!=fb){
    //     father[fa]=fb;
    // }
    if(fa<=fb){
        father[fb]=fa;
    }else{
        father[fa]=fb;
    }
}
int main()
{
    // vector<int> estate,area;
    int n,id,fa,mo,k,ch,es,ar;
    for(int i=0;i<n;i++){
        cin >> id >> fa >> mo >> k;
        Union(id,fa);
        Union(id,mo);
        for(int j=0;j<k;j++){
            cin >> ch;
            Union(id,ch);
        }
        cin >> es >> ar;
        // int root=findFather(id);
        // estate[root]+=es;
        // area[root]+=ar;
    }
    int res=0;
    set<int> s;
    for(int i=0;i<=maxn;i++){
        isRoot[findFather(i)]=true;
        s.insert(findFather(i));
    }
    for(int i=0;i<=maxn;i++){
        res+=isRoot[i];
    }
    cout << res << endl;
    cout << s.size() << endl;
    sort(s.begin(),s.end());
    for(auto it=s.begin();it!=s.end();it++){
        cout << *it << " " << endl;
    }
    return 0;
}