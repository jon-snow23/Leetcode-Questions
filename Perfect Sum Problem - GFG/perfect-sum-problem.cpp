//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        int MOD = 1000000007;
        vector<int> dp(sum + 1, 0);

        // Initialize the base case
        dp[0] = 1; // There is always one way to make sum 0 with an empty subset if 0 is present in the array.

        // Fill the dp table
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }

        return dp[sum];
    }
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends