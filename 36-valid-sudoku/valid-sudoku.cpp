class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 rows, 9 columns, and 9 boxes
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '1';

                // Find which 3x3 box the cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Check for duplicate
                if (rows[i][num] || cols[j][num] || boxes[box][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};