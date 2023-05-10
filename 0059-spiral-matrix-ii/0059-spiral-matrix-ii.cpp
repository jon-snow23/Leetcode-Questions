class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1; // current number to fill in the matrix
        int row_start = 0, row_end = n - 1; // boundaries of rows to fill
        int col_start = 0, col_end = n - 1; // boundaries of columns to fill
        
        while (row_start <= row_end && col_start <= col_end) {
            // fill the top row
            for (int i = col_start; i <= col_end; i++) {
                matrix[row_start][i] = num++;
            }
            row_start++;
            
            // fill the right column
            for (int i = row_start; i <= row_end; i++) {
                matrix[i][col_end] = num++;
            }
            col_end--;
            
            if (row_start <= row_end) { // prevent duplicates when n is odd
                // fill the bottom row
                for (int i = col_end; i >= col_start; i--) {
                    matrix[row_end][i] = num++;
                }
                row_end--;
            }
            
            if (col_start <= col_end) { // prevent duplicates when n is odd
                // fill the left column
                for (int i = row_end; i >= row_start; i--) {
                    matrix[i][col_start] = num++;
                }
                col_start++;
            }
        }
        
        return matrix;
    }
};
