#include<iostream>
using namespace std;
int main()
{
    double a[3][3];
    char c[]={'W','T','L'};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    double profit=0,t=1;
    for(int i=0;i<3;i++){
        int max;
        double maxn=-1;
        for(int j=0;j<3;j++){
            if(a[i][j]>maxn){
                max=j;
                maxn=a[i][j];
            }
        }
        cout << c[max] << " ";
        t*=maxn;
    }
    profit=(t*0.65-1)*2.0;
    printf("%.2f",profit);
    return 0;
}