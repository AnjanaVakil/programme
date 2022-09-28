#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k,t;
    cin >> n;
    int c[101]={0};
    for(int i=0;i<n;i++){
        cin >> t;
        c[t]++;
    }
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> t;
        if(i!=0) cout << " ";
        cout << c[t];
    }
    return 0;
}