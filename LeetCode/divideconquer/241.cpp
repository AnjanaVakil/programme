//分治法
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i=0;i<expression.length();i++){
            char ch=expression[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                 vector<int> leftres=diffWaysToCompute(expression.substr(0,i));
            vector<int> rightres=diffWaysToCompute(expression.substr(i+1));
            for(const int & left:leftres){
                for(const int & right:rightres){
                    switch(ch){
                        case '+':res.push_back(left+right);break;
                        case '-':res.push_back(left-right);break;
                        case '*':res.push_back(left*right);break;
                    }
                }
            }
            }
        }
        //只有数字
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
//动态规划
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> data;
        vector<char> ops;
        int num=0;
        char op=' ';
        istringstream ss(expression+"+");
        while(ss>>num && ss>>op){
            data.push_back(num);
            ops.push_back(op);
        }
        int n=data.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>()));
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;--j){
                if(i==j){
                    dp[j][i].push_back(data[i]);
                }else{
                    for(int k=j;k<i;k+=1){
                        for(auto left:dp[j][k]){
                            for(auto right:dp[k+1][i]){
                                int val=0;
                                switch(ops[k]){
                                    case '+':val=left+right;break;
                                    case '-':val=left-right;break;
                                    case '*':val=left*right;break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};