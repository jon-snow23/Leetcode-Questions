#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> rowCount(m, 0);  // To store the count of 1s in each row
        std::vector<int> colCount(n, 0);  // To store the count of 1s in each column

        // Count 1s in each row and each column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int specialPositions = 0;

        // Check for special positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    specialPositions++;
                }
            }
        }

        return specialPositions;
    }
};
