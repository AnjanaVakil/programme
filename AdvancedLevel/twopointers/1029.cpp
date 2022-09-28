#include<iostream>
#include<vector>
#include<climits>
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn];
//22'
int main()
{
    // cout << INT_MAX << " " << INT_MIN << endl;
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    a[n]=a[m]=INT_MAX;
    //increasing sequence;
    //思路是对的，但这个代码真的不简洁，写的是真垃圾，所以为什么不多花时间练习呢！
    int mid=(n+m-1)/2;
    int i=0,j=0;
    int cnt=0;
    while(cnt<mid){
        if(a[i]<b[j]){
            i++;
        }else{
            j++;
        }
        cnt++;
    }
    if(a[i]<=b[j]){
        cout << a[i];
    }else{
        cout << b[j];
    }
    return 0;
}