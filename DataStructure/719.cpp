#include<iostream>
#include<algorithm>
#define maxn 1000000
int a[maxn];
using namespace std;
int main()
{
    int k,n;
    cin >> k;
    int i=0;
    while(cin >> n && n>=0){
        a[i++]=n;
    }
    reverse(a,a+i);
    if(k>=1 && k<=i){
        cout << a[k-1];
    }else{
        cout << "NULL";
    }
    return 0;
}