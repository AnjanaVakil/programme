//暴力递归 -->超出时间限制
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return -1;
        
        int res=INT_MAX;
        for(int coin:coins){
            int subproblem=coinChange(coins,amount-coin);
            if(subproblem==-1) continue;
            else res=min(res,subproblem+1);
        }
        
        return res!=INT_MAX?res:-1;
    }
};
//带备忘录的递归
class Solution {
public:
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0; 
        memo.resize(amount+1,-666);
        return dp(coins,amount);
    }
    int dp(vector<int>& coins,int rem){
        if(rem==0) return 0;
        if(rem<0) return -1;
        if(memo[rem]!=-666) return memo[rem];
        int res=INT_MAX;
        for(int coin:coins){
            int subproblem=dp(coins,rem-coin);
            if(subproblem==-1) continue;
            else res=min(res,subproblem+1);
        }
        memo[rem]=(res==INT_MAX?-1:res);
        return memo[rem];
    }
};
//dp数组的迭代
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp数组初始化为特殊值amount+1
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<dp.size();i++){
            for(int coin:coins){
                if(i-coin<0) continue;
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};