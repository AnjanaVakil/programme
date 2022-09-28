#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//14:28-45 25score
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }
    //10
    //23 8 10 99 46 2333 46 1 666 555
    //1 8 10 23 46 46 99   555 666 2333
    sort(v.begin(),v.end());
    int halfsum=0;
    for(int i=0;i<v.size()/2;i++){
        halfsum+=v[i];
    }
    printf("%d %d",n%2,sum-2*halfsum);
    return 0;
}