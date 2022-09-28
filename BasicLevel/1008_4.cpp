#include<iostream>
using namespace std;
int a[105];
//20'
int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    m=m%n;//如果m大于n，那么循环右移m位相当于循环右移m%n位，因为那些n倍数位的移动是多余的，所以在使用m之前，先将m = m%n
    int count=0;
    for(int i=n-m;i<n;i++){
        cout << a[i];
        count++;
        if(count<n) cout << " ";
    }
    for(int i=0;i<=n-m-1;i++){
        cout << a[i];
        count++;
        if(count<n) cout << " ";
    }
    return 0;
}