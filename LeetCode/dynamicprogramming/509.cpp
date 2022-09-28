//暴力递归 时间复杂度O(2^n)
class Solution {
public:
    int fib(int n) {
        // if(n==0) return 0;
        // if(n==1) return 1;
        if(n<2) return n;
        return fib(n-1)+fib(n-2);
    }
};
//带备忘录的递归解法 时间复杂度O(n)
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<int> memo(n+1,0);
        return helper(memo,n);
    }
    int helper(vector<int>& memo,int n)
    {
        if(n<2) return n;
        if(memo[n]!=0) return memo[n];
        memo[n]=helper(memo,n-1)+helper(memo,n-2);
        return memo[n];
    }
};
//dp数组的迭代解法 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<int> dp(n+1,0);
        //base case
        dp[1]=dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//dp数组的迭代解法 时间复杂度O(n) 空间复杂度O(1) -->状态压缩
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int prev=1,curr=1;
        for(int i=3;i<=n;i++){
            int sum=prev+curr;
            prev=curr;
            curr=sum;
        }
        return curr;
    }
};


