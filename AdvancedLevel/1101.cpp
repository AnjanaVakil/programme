//19:54-自己没有独立写出来
#include<iostream>
#include<climits>
using namespace std;
const int N=100005;
int a[N],leftMax[N],rightMin[N];
int res[N];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    leftMax[0]=0;
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],a[i-1]);
    }
    rightMin[n-1]=INT_MAX;
    for(int i=n-2;i>=0;i--){
        rightMin[i]=min(rightMin[i+1],a[i+1]);
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(leftMax[i]<a[i] && a[i]<rightMin[i]){
            res[j++]=a[i];
        }
    }
    cout << j << "\n";
    for(int k=0;k<j;k++){
        cout << res[k];
        if(k!=j-1) cout << " ";
    }
    cout << "\n";
    return 0;
}