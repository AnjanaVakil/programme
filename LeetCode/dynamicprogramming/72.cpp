//Dynamic Programming 时间复杂度O(MN) 空间复杂度O(MN)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int c=0;
                //注意：这里是i-1和j-1 不是i和j
                if(word1[i-1]!=word2[j-1]){
                    c=1;
                }
                int up=dp[i-1][j]+1; //delete
                int left=dp[i][j-1]+1; //insert
                int left_up=dp[i-1][j-1]+c; //replace
                // dp[i][j]=min(left,min(up,left_up));
                dp[i][j]=min({up,left,left_up});
            }
        }
        return dp[m][n];
    }
};
//
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int up=dp[i-1][j]+1; //delete
                int left=dp[i][j-1]+1; //insert
                int left_up=dp[i-1][j-1]; //replace
                if(word1[i-1]!=word2[j-1]) left_up+=1;
                // dp[i][j]=min(left,min(up,left_up));
                dp[i][j]=min({up,left,left_up});
            }
        }
        return dp[m][n];
    }
};