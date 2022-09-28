//13:14- 还是有需要注意的点
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double temp;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin >> temp;
        sum+=(long long)(temp*1000)*i*(n-i+1);
        // cout << sum << endl;
    }
    printf("%.2f",sum/1000.0);
    return 0;
}