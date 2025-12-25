class Solution {
public:
    vector<vector<char>> board;

    bool canPlaceQueen(int row, int col, int n) {
        // Column check
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // Left diagonal check
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Right diagonal check
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(vector<vector<string>>& res, int row, int n) {
        if (row == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string str;  
                for (int j = 0; j < n; j++) {
                    str.push_back(board[i][j]);
                }
                temp.push_back(str);
            }
            res.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {  
            if (canPlaceQueen(row, col, n)) {
                board[row][col] = 'Q';
                helper(res, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, vector<char>(n, '.'));

        vector<vector<string>> res;

        helper(res, 0, n);
        
        return res;
    }
};
