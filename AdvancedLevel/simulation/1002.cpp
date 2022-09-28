#include<iostream>
using namespace std;
//It is given that 1≤K≤10，0≤NK<⋯<N2<N1≤1000.
//题目比较简单，但要认真读题，看清楚
//K的取值范围 和 NK即指数的取值范围
double res[1001];
int main()
{
    int k1,k2,expon;
    double coef;
    cin >> k1;
    for(int i=0;i<k1;i++){
        cin >> expon >> coef;
        res[expon]+=coef;
    }
    cin >> k2;
    for(int i=0;i<k2;i++){
        cin >> expon >> coef;
        res[expon]+=coef;
    }
    int cnt=0;
    for(int i=1001;i>=0;i--){
        if(res[i]!=0){
            cnt++;
        }
    }
    cout << cnt;
    for(int i=1001;i>=0;i--){
        if(res[i]!=0){
            printf(" %d %.1f",i,res[i]);
        }
    }
}