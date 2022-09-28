//
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(),n=text2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
//MOOC
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> C(n+1,vector<int>(m+1));
        vector<vector<string>> rec(n+1,vector<string>(m+1));
        //初始化
        for(int i=0;i<=n;i++) C[i][0]=0;
        for(int j=0;j<=m;j++) C[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    C[i][j]=C[i-1][j-1]+1;
                    rec[i][j]="LU";
                }else{
                    // C[i][j]=max(C[i-1][j],C[i][j-1]);
                    if(C[i-1][j]>C[i][j-1]){
                        C[i][j]=C[i-1][j];
                        rec[i][j]="U";
                    }else{
                        C[i][j]=C[i][j-1];
                        rec[i][j]="L";
                    }
                }
            }
        }
        return C[n][m];
    }
    void printLCS(vector<vector<string>> rec,vector<string> text1,int i,int j){
        //递归终止
        if(i==0 || j==0) return;
        if(rec[i][j]=="LU"){
            printLCS(rec,text1,i-1,j-1);
            printf("%s",text1[i].c_str());
        }else if(rec[i][j]=="U"){
            printLCS(rec,text1,i-1,j);
        }else{
            printLCS(rec,text1,i,j-1);
        }
    }
};

