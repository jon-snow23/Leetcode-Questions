#include <vector>

class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        const int MOD = 1000000007;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[x][y] = 1;
        int count = 0;

        for (int moves = 1; moves <= N; moves++) {
            std::vector<std::vector<int>> temp(m, std::vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) count = (count + dp[i][j]) % MOD;
                    if (j == n - 1) count = (count+ dp[i][j]) % MOD;
                    if (i == 0) count = (count + dp[i][j]) % MOD;
                    if (j == 0) count = (count + dp[i][j]) % MOD;

                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % MOD +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % MOD
                    ) % MOD;
                }
            }

            dp = temp;
        }

        return count;
    }
};
