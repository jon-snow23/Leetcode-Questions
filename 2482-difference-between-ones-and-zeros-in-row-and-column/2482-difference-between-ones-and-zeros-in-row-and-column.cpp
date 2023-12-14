#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> onesRow(m, 0);
        std::vector<int> onesCol(n, 0);
        std::vector<int> zerosRow(m, 0);
        std::vector<int> zerosCol(n, 0);

        // Calculate the number of ones and zeros in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
                zerosRow[i] += (1 - grid[i][j]);
                zerosCol[j] += (1 - grid[i][j]);
            }
        }

        // Create the difference matrix
        std::vector<std::vector<int>> diff(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return diff;
    }
};
