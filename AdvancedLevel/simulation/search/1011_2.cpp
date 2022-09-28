#include<iostream>
using namespace std;
int main()
{
    double ans=1.0;
    char c[]={"WTL"};
    for(int i=0;i<3;i++){
        int max=0;
        double maxn=0.0;
        for(int j=0;j<3;j++){
            double temp;
            cin >> temp;
            if(temp>maxn){
                max=j;
                maxn=temp;
            }
        }
        cout << c[max] <<  " ";
        ans*=maxn;
    }
    printf("%.2f",(ans*0.65-1)*2);
    return 0;
}