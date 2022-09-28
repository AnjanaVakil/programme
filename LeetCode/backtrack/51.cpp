//
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(board,0);
        return res;
    }
    void backtrack(vector<string>& board,int row)
    {
        //触发结束条件
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        int n=board[row].size();
        for(int col=0;col<n;col++){
            //排除不合法选择
            if(!isValid(board,row,col)) continue;
            //选择
            board[row][col]='Q';
            //进入下一行决策
            backtrack(board,row+1);
            //撤销选择
            board[row][col]='.';
        }
    }
    bool isValid(vector<string>& board,int row,int col){
        int n=board.size();
        //列
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //左上方
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //右上方
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
};