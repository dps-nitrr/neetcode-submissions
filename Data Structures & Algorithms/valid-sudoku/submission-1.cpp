class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int row){
        unordered_map<char, int>mp;
        for(int i=0;i<9;i++){
            char c=board[row][i];
            if(c=='.')continue;
            if(mp.find(c) !=mp.end())return false;
            mp[ c]++;
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col){
        unordered_map<char, int>mp;
        for(int i=0;i<9;i++){
            char c=board[i][col];
            if(c=='.')continue;
            if(mp.find(c) !=mp.end())return false;
            mp[c]++;
        }
        return true;
    }

    bool checkGrid(vector<vector<char>>& board, int row, int col){
        unordered_map<char, int>mp;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
            char c=board[i][j];
            if(c=='.')continue;
              
             if(mp.find(c) !=mp.end())return false;
            mp[c]++;

            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)if(!checkRow(board, i))return false;
        for(int i=0;i<9;i++)if(!checkCol(board, i))return false;
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!checkGrid(board, i, j))return false;
            }
        }
        return true;
        
    }
};
