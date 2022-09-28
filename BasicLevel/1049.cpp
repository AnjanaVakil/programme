#include<iostream>
using namespace std;
#define maxn 100005
//部分正确 15‘
//建议不要使用double类型进行多次累加的精确计算，而是转为能够精确存储的整型
double a[maxn];
int main()
{
    int n;
    cin >> n;
    double res=0.00;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            res+=(a[j]*(n-j));
        }
    }
    printf("%.2lf",res);
    return 0;
}