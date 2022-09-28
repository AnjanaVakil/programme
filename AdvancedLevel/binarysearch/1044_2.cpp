#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//25'
//sum递增 二分查找
vector<int> sum(100010,0);
//第一个大于target的值
int upper_bound(int target,int left,int right)
{
    while(left<right){
        int mid=left+(right-left)/2;
        if(sum[mid]>target){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    //这样计算sum[i]的方法有点笨，可以在输入的时候直接计算sum[i]
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<i;j++){
    //         sum[i]+=d[j];
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     cout << sum[i] << " ";
    // }
    // cout << endl;
    vector<int> res(n+1,0);
    int nearSum=INT_MAX;
    for(int i=1;i<=n;i++){ //左端点
        int j=upper_bound(sum[i-1]+m,i,n+1); //右端点
        if(sum[j-1]-sum[i-1]==m){
            nearSum=m;
            break;
        }else if(j<=n && sum[j]-sum[i-1]<nearSum){
            nearSum=sum[j]-sum[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        int j=upper_bound(sum[i-1]+nearSum,i,n+1);
        if(sum[j-1]-sum[i-1]==nearSum){
            printf("%d-%d\n",i,j-1);
        }
    }
    return 0;
}