class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int x, int y, int num){
        for(int i=0;i<9;i++){
            if(board[i][y] - '0'== num) return false;
            if(board[x][i] - '0'== num) return false;
        }    
        int BRow = (x/3)*3;
        int BCol = (y/3)*3;
        for(int i = BRow; i < BRow + 3; i++){
            for(int j = BCol; j < BCol + 3; j++){
                if(board[i][j] - '0' == num)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int x, int y){
        if(x==9) return true;
        if(y==9) return solve(board,x+1,0);
        if(board[x][y] != '.') return solve(board,x,y+1);
        for(char num=1;num<=9;num++){
            if(isPossible(board,x,y,num)){
                board[x][y] = '0' + num;
                
                bool a = solve(board,x,y+1);
                if(a) return true;

                board[x][y] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
