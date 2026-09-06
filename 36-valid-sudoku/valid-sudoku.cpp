class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board) {
        if (board[row][col] == '.')
            return true;

        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][col] == board[row][i])
                return false;
            if (i != row && board[row][col] == board[i][col])
                return false;

            if (((3 * (row / 3) + (i / 3)) != row ||
                 (3 * (col / 3) + (i % 3)) != col) &&
                board[row][col] ==
                    board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)])
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isValid(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};