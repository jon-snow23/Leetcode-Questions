class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        
        // Create a boolean table to store if a substring is palindrome or not.
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // All single characters are palindromes.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            count++;
        }
        
        // Check for palindromes of length 2.
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }
        
        // Check for palindromes of length greater than 2.
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
};
