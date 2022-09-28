#include<iostream>
#include<vector>
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn];
// 25'
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    int mid=(n+m+1)/2;
    int i=1,j=1,cnt=0,ans;
    while(i<=n && j<=m){
        ans=(a[i]<=b[j])?a[i++]:b[j++];
        if(++cnt==mid) break;
    }
    if(i<=n && cnt<mid){
        ans=a[i+mid-cnt-1];
    }else if(j<=m && cnt<mid){
        ans=b[j+mid-cnt-1];
    }
    cout << ans;
    return 0;
}