#include<iostream>
using namespace std;
int main()
{
    int n,a[10],res=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                res+=a[i]*10+a[j];
            }
        }
    }
    cout << res;
    return 0;
}