#include<iostream>
#include<vector>
using namespace std;
const int maxn=60;
//20'
int main()
{
    int n;
    cin >> n;
    int a,b;
    vector<int> v(maxn+1);
    v[0]=0;
    v[1]=1;
    for(int i=2;i<=maxn;i++){
        v[i]=v[i-1]+v[i-2];
    }
    for(int i=1;i<maxn;i++){
        if(n>v[i]) continue;
        else{
            b=v[i-1];
            a=v[i];
            break;
        } 
    }
    if(n-b<=a-n) cout << b;
    else cout << a;
    return 0;
}