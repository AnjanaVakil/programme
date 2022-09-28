#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,a,b;
    cin >> n;
    double max=0;
    while(n--){
        cin >> a >> b;
        double t=pow((a*a+b*b),0.5);
        if(t>=max){
            max=t;
        }
    }
    printf("%.2f",max);
    return 0;
}