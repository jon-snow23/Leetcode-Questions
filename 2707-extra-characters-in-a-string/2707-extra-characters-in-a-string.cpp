#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n = s.length();
        std::vector<int> dp(n + 1, n); // Initialize dp array with maximum values
        dp[0] = 0;

        std::unordered_set<std::string> dict;
        for (const std::string& word : dictionary) {
            dict.insert(word);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j >= 1; j--) {
                std::string substring = s.substr(j - 1, i - j + 1);
                if (dict.count(substring)) {
                    dp[i] = std::min(dp[i], dp[j - 1]);
                } else {
                    dp[i] = std::min(dp[i], dp[j - 1] + i - j + 1);
                }
            }
        }

        return dp[n];
    }
};
