#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//自己直接搬了二分查找的代码，写的都是int类型，所以导致一直出错
//但是这里要比较的num[i]*p，可能超过int类型吗，所以使用long long类型
//upper_bound大于目标值的第一个元素
int upper_bound(vector<int>& nums,long long target,int i)
{
    int n=nums.size();
    if(nums[n-1]<=target) return n;
    int left=i+1,right=n-1;
    while(left<right){
        int mid=(left+right)/2;
        if(nums[mid]>target){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
int main()
{
    //p是不超过10^9，但是如果相乘那就可能超过了，所以类型为long long类型
    int n;
    long long p;
    cin >> n >> p;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    int result=1;
    for(int i=0;i<n;i++){
        //在i+1到n-1中查找
        //这里要转换为long long类型
        int j=upper_bound(num,(long long)num[i]*p,i);
        result=max(j-i,result);
    }
    cout << result;
    return 0;
}