//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int count(int coins[], int N, int sum) {
        long long int dp[sum + 1];
        memset(dp, 0, sizeof(dp));  // Initialize dp array with 0

        dp[0] = 1;  // Base case

        for (int j = 0; j < N; j++) {
            for (int i = coins[j]; i <= sum; i++) {
                dp[i] += dp[i - coins[j]];
            }
        }

        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends