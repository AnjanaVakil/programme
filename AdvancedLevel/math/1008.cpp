#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,total=0;
    cin >> n;
    vector<int> f(n);
    for(int i=0;i<n;i++){
        cin >> f[i];
    }
    total+=(f[0]*6);
    //12 6 8 15 =41
    for(int i=1;i<n;i++){
        int t=f[i]-f[i-1];
        if(t>=0){
            total+=(t*6);
        }
        else if(t<0){
            total+=((-t)*4);
        }
    }
    total+=(n*5);
    cout << total;
    return 0;
}