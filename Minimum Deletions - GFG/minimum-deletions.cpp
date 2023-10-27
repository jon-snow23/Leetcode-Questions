//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minimumNumberOfDeletions(string S) {
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: Single characters are palindromes by default
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Fill the dp table using bottom-up approach
        for (int cl = 2; cl <= n; ++cl) {
            for (int i = 0; i < n - cl + 1; ++i) {
                int j = i + cl - 1;
                if (S[i] == S[j] && cl == 2) {
                    dp[i][j] = 2;
                } else if (S[i] == S[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        // Minimum number of deletions = Length of input string - Length of longest palindromic subsequence
        return n - dp[0][n - 1];
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends