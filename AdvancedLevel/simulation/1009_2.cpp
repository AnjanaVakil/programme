#include<iostream>
#include<vector>
using namespace std;
//It is given that 1≤K≤10，0≤NK<⋯<N2<N1≤1000.
//因为相乘后指数可能最大为2000，所以ans数组最大要开到2001
double arr[1001],res[2001];
int main()
{
    int k1,k2,expon;
    double coef;
    cin >> k1;
    for(int i=0;i<k1;i++){
        cin >> expon >> coef;
        arr[expon]=coef;
    }
    cin >> k2;
    for(int i=0;i<k2;i++){
        cin >> expon >> coef;
        for(int j=0;j<1001;j++){
            res[j+expon]+=(arr[j]*coef);
        }
    }
    int cnt=0;
    for(int i=2001;i>=0;i--){
        if(res[i]!=0){
            cnt++;
        }
    }
    cout << cnt;
    for(int i=2001;i>=0;i--){
        if(res[i]!=0){
            printf(" %d %.1f",i,res[i]);
        }
    }
}