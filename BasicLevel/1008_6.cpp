#include<iostream>
using namespace std;
int a[105];
//20'
void reverse(int i,int j)
{
    for(int k=0;k<(j-i+1)/2;k++){
        int temp=a[i+k];
        a[i+k]=a[j-k];
        a[j-k]=temp;
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    m=m%n;
    reverse(0,n-1);
    reverse(0,m-1);
    reverse(m,n-1);
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    return 0;
}