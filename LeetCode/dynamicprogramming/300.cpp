//子串一定是连续的，而子序列不一定是连续的
//动态规划 时间复杂度 O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。
        //最终结果（子序列的最大长度）应该是 dp 数组中的最大值。
        //base case
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int res=dp[0];
        for(int i=1;i<n;i++){
            if(dp[i]>res){
                res=dp[i];
            }
        }
        return res;
    }
};
//
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。
        //最终结果（子序列的最大长度）应该是 dp 数组中的最大值。
        //base case
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        //return *max_element(dp.begin(),dp.end());
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,dp[i]);
        }
        return res;
    }
};
//二分查找 时间复杂度 O(logN)
