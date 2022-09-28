#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//AC
int main()
{
    //p是不超过10^9，但是如果相乘那就可能超过了，所以将类型转换成long long类型
    int n;
    long long p;
    cin >> n >> p;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    int result=0;
    for(int i=0;i<n;i++){
        //寻找第一个超过num[i]*p的位置j
        int j=upper_bound(num.begin(),num.end(),num[i]*p)-num.begin();
        result=max(j-i,result);
    }
    cout << result;
    return 0;
}