#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//16:50-17:02 12min 22'
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
    int left=0,right=num.size()-1;
    int res1;
    while(left<=right){
        if(num[right]<=(long long)num[left]*p){
            res1=(right-left+1);
            break;
        }else{
            right--;
        }
    }
    left=0,right=num.size()-1;
    int res2;
    while(left<=right){
        if(num[right]<=(long long)num[left]*p){
            res2=(right-left+1);
            break;
        }else{
            left++;
        }
    }
    if(res1>res2) cout << res1;
    else cout << res2;
    return 0;
}