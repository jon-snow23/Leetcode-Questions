class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        int maxi = t[n - 1]; 

        for (int i = n - 2; i >= 0; --i) {
            if (t[i] >= maxi) {
                ans[i] = 0;
                maxi = t[i];
            } else {
                int j = i + 1;
                // Iterate through the days in the future until a warmer day is found
                while (j < n && t[j] <= t[i]) {
                    // Skip days with temperatures less than or equal to the current day
                    j += ans[j] == 0 ? 1 : ans[j];
                }
                if (j < n) {
                    ans[i] = j - i;  // Number of days waited for a warmer temperature
                } else {
                    ans[i] = 0;  // No warmer day found in the future
                }
            }
        }

        return ans;
    }
};
