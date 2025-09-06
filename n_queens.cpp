class Solution {

public:
    vector<vector<string>>ans;
    bool is_safe(vector<string>& board,int row,int col,int n){
        for(int i=0;i<col;i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
public:
    void solve(vector<string>& board,int col,int n){
        if(col>=n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(is_safe(board,i,col,n)){
                board[i][col] = 'Q';
                solve(board,col+1,n);
                board[i][col] = '.';
            
        }
    }
    
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        solve(board,0,n);
        return ans;
    }
};
