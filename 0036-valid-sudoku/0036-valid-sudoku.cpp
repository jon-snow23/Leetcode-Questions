class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> colCounts(9, vector<int>(9, 0));
        vector<vector<int>> subBoxCounts(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            vector<int> rowCount(9, 0);

            for (int j = 0; j < 9; j++) {
                char c = board[i][j];

                if (c == '.')
                    continue;

                int idx = c - '1';

                int &rc = rowCount[idx];

                if (rc == 1)
                    return false;

                rc++;

                int &cc = colCounts[j][idx];

                if (cc == 1)
                    return false;

                cc++;

                int subBoxIdx = (i / 3) * 3 + j / 3;

                int &sc = subBoxCounts[subBoxIdx][idx];

                if (sc == 1)
                    return false;

                sc++;
            }
        }

        return true;
    }
};