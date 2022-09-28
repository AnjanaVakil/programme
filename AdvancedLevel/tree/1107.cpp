#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
//isRoot 以x作为根结点的网络中有多少人
int father[maxn],hobby[maxn],isRoot[maxn];
// int findFather(int x)
// {
//     while(x!=father[x]){
//         x=father[x];
//     }
//     return x;
// }
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
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb){
        father[fa]=fb;
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        father[i]=i;
        isRoot[i]=0;
    }
    int k;
    char c;
    for(int i=1;i<=n;i++){
        cin >> k >> c;
        int h;
        for(int j=0;j<k;j++){
            cin >> h;
            if(hobby[h]==0){
                //hobby第一次被人喜欢
                hobby[h]=i;
            }
            Union(i,findFather(hobby[h]));
        }
    }
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(isRoot[i]!=0) ans++;
    }
    cout << ans << endl;
    sort(isRoot+1,isRoot+n+1,cmp);
    for(int i=1;i<=ans;i++){
        if(i!=1) cout << " ";
        cout << isRoot[i];
    }
    return 0;
}