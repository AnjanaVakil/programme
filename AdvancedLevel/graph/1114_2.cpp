#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct node{
    int id,people;
    double num,area;
    bool flag=false;
}ans[maxn];
struct DATA{
    int id,fid,mid,num,area;
    int cid[10];
}data[maxn];
int father[maxn];
bool vis[maxn];
int cmp(node a,node b){
    if(a.area!=b.area) return a.area>b.area;
    else return a.id<b.id;
}
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
    if(fa<fb){
        father[fb]=fa;
    }else if(fa>fb){
        father[fa]=fb;
    }
}
int main()
{
    int n,k;
    scanf("%d", &n);
    for(int i=0;i<maxn;i++){
        father[i]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        vis[data[i].id]=true;
        if(data[i].fid!=-1){
            vis[data[i].fid]=true;
            Union(data[i].id,data[i].fid);
        }
        if(data[i].mid!=-1){
            vis[data[i].mid]=true;
            Union(data[i].id,data[i].mid);
        }
        for(int j=0;j<k;j++){
            cin >> data[i].cid[j];
            vis[data[i].cid[j]]=true;
            Union(data[i].id,data[i].cid[j]);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i=0;i<n;i++){
        int id=findFather(data[i].id);
        ans[id].id=id;
        ans[id].num+=data[i].num;
        ans[id].area+=data[i].area;
        ans[id].flag=true;
    }
    int cnt=0;
    for(int i=0;i<maxn;i++){
        if(vis[i]){
            ans[findFather(i)].people++;
        }
        if(ans[i].flag) cnt++;
    }
    for(int i=0;i<maxn;i++){
        if(ans[i].flag){
            ans[i].num=(double)(ans[i].num*1.0)/ans[i].people;
            ans[i].area=(double)(ans[i].area*1.0)/ans[i].people;
        }
    }
    cout << cnt << endl;
    sort(ans,ans+maxn,cmp);
    for(int i=0;i<cnt;i++){
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
    }
    return 0;
}