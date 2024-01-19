#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Create a DP matrix to store minimum falling path sum
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Initialize the first row of the DP matrix with the values from the input matrix
        for (int col = 0; col < n; ++col) {
            dp[0][col] = matrix[0][col];
        }

        // Calculate the minimum falling path sum for each cell in the DP matrix
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                // Update the current cell with the minimum falling path sum
                dp[row][col] = matrix[row][col] + std::min({
                    (col > 0) ? dp[row - 1][col - 1] : INT_MAX,
                    dp[row - 1][col],
                    (col < n - 1) ? dp[row - 1][col + 1] : INT_MAX
                });
            }
        }

        // Find the minimum falling path sum in the last row of the DP matrix
        int result = *std::min_element(dp[n - 1].begin(), dp[n - 1].end());

        return result;
    }
};

