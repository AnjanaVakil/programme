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
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    //10
    // 6 7 6 9 3 10 8 2 7 8
    // 10 9 8 8 7 7 6 6 3 2 
    // for(int i=0;i<n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int i;
    for(i=1;i<=n;i++){
        if(a[i]<=i){
            // cout << i-1;
            break;
        }
    }
    cout << i-1;
    return 0;
}