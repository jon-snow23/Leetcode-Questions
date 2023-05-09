class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int row = 0, col = 0;
        int dir = 0; // 0: right, 1: down, 2: left, 3: up
        while (top <= bottom && left <= right) {
            result.push_back(matrix[row][col]);
            switch (dir) {
                case 0:
                    if (col == right) {
                        dir = 1;
                        top++;
                        row++;
                    } else {
                        col++;
                    }
                    break;
                case 1:
                    if (row == bottom) {
                        dir = 2;
                        right--;
                        col--;
                    } else {
                        row++;
                    }
                    break;
                case 2:
                    if (col == left) {
                        dir = 3;
                        bottom--;
                        row--;
                    } else {
                        col--;
                    }
                    break;
                case 3:
                    if (row == top) {
                        dir = 0;
                        left++;
                        col++;
                    } else {
                        row--;
                    }
                    break;
            }
        }
        return result;
    }
};