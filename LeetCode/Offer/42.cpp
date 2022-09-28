class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //蛮力枚举：超出时间限制 O(N^3)
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                if(sum>max) max=sum;
            }
        }
        return max;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //优化枚举：超出时间限制 O(N^2)
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>max) max=sum;
            }
        }
        return max;
    }
};
//分而治之 测试未通过
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //分而治之 O(logN)
        return SubArray(nums,0,nums.size()-1);
    }
    int SubArray(vector<int>& nums,int low,int high){
        //递归终止条件
        if(low==high) return nums[low];
        int mid=(low+high)/2;
        int s1=SubArray(nums,low,mid);
        int s2=SubArray(nums,mid+1,high);
        int s3=crossingSubArray(nums,low,mid,high);
        int smax=max({s1,s2,s3});
        return smax;
    }
    int crossingSubArray(vector<int>& nums,int low,int mid,int high){
        int sleft=INT_MIN,sum=0;
        for(int l=mid;l>=low;l--){
            sum+=nums[l];
            if(sum>sleft) sleft=sum;
        }
        int sright=INT_MIN;
        sum=0;
        for(int r=mid+1;r<high;r++){
            sum+=nums[r];
            if(sum>sright) sright=sum;
        }
        int s3=sleft+sright;
        return s3;
    }
};
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划 O(N)
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        int res=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=nums[i]+max(dp[i-1],0);
            res=max(dp[i],res);
        }
        return res;
    }
};
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> D(n+1),Rec(n+1);
        //初始化
        D[n-1]=nums[n-1];
        Rec[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(D[i+1]>0){
                D[i]=nums[i]+D[i+1];
                Rec[i]=Rec[i+1];
            }else{
                D[i]=nums[i];
                Rec[i]=i;
            }
        }
        int Smax=D[0]; //最大子数组和Smax
        int l,r; //子数组起止位置
        for(int i=1;i<n;i++){
            if(D[i]>Smax){
                Smax=D[i];
                l=r;
                r=Rec[i];
            }
        }
        return Smax;
    }
};
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(dp[i-1]>0){
                dp[i]=nums[i]+dp[i-1];
            }else{
                dp[i]=nums[i];
            }
        }
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(dp[i]>max){
                max=dp[i];
            }
        }
        return max;
    }
};


