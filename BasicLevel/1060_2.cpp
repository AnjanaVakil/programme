#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin >> n;
    int a[100000];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    // for(int i=1;i<=n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int ans=0,p=1;
    while(ans<=n && a[p]>p){
        ans++;
        p++;
    }
    printf("%d",ans);
    return 0;
}