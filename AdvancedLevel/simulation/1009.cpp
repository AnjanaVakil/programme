#include<iostream>
#include<vector>
using namespace std;
//It is given that 1≤K≤10，0≤NK<⋯<N2<N1≤1000.
struct poly{
    double coef;
    int expon;
};
//因为相乘后指数可能最大为2000，所以ans数组最大要开到2001
double res[2001];
int main()
{
    int k1,k2;
    cin >> k1;
    vector<poly> a(11),b(11);
    for(int i=0;i<k1;i++){
        cin >> a[i].expon >> a[i].coef;
    }
    cin >> k2;
    for(int i=0;i<k2;i++){
        cin >> b[i].expon >> b[i].coef;
    }
    for(int i=0;i<k1;i++){
        for(int j=0;j<k2;j++){
            res[a[i].expon+b[j].expon]+=(a[i].coef*b[j].coef);
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