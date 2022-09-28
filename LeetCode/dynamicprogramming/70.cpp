//超出时间限制
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
//带备忘录的递归算法
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> memo(n+1,0);
        return helper(memo,n);
    }
    int helper(vector<int>& memo,int n)
    {
        if(memo[n]!=0) return memo[n];
        if(n<=2) return n;
        memo[n]=helper(memo,n-1)+helper(memo,n-2);
        return memo[n];
    }
    
};
//带dp数组的迭代算法
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
class Solution {
public:
    int climbStairs(int n) {
        //因为我们每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达
        //换句话说，走到第 i 阶的方法数即为走到第 i-1 阶的方法数加上走到第 i-2 阶的方法数。
        if(n<=2) return n;
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//状态压缩
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int first=1,second=2,third;
        for(int i=3;i<=n;i++){
            third=first+second;
            first=second;
            second=third;
        }
        return second;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        //因为我们每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达
        //换句话说，走到第 i 阶的方法数即为走到第 i-1 阶的方法数加上走到第 i-2 阶的方法数。
        if(n<=2) return n;
        int prev2=1,prev1=2,curr;
        for(int i=3;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
//矩阵快速幂 时间复杂度:同快速幂 O(logn) 空间复杂度O(1)
class Solution{
    public:
    vector<vector<long long>> multiply(vector<vector<long long>>& a,vector<vector<long long>>& b){
        vector<vector<long long>> c(2,vector<long long>(2));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
            }
        }   
        return c;
    }
    
    vector<vector<long long>> matrixPow(vector<vector<long long>>& a,int n){
        vector<vector<long long>> ret={{1,0},{0,1}};
        while(n>0){
            if((n&1)==1){
                ret=multiply(ret,a);
            }
            n>>=1;
            a=multiply(a,a);
        }
        return ret;
    }
    
    int climbStairs(int n){
        vector<vector<long long>> ret={{1,1},{1,0}};
        vector<vector<long long>> res=matrixPow(ret,n);
        return res[0][0];
    }
};
//通项公式
class Solution{
    public:
    int climbStairs(int n){
        double sqrt5=sqrt(5);
        double fibn=pow((1+sqrt5)/2,n+1)-pow((1-sqrt5)/2,n+1);
        return (int)round(fibn/sqrt5);
    }
};

