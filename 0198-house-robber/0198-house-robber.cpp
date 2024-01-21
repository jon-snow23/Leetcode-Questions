class Solution {
public:
    int solve(vector<int> &nums, int &ans, int sum, int i, vector<int> &dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int t = max(solve(nums, ans, sum, i+2, dp)+nums[i], solve(nums, ans, sum, i+1, dp));
        //cout<<t<<endl;
        return dp[i] = t;
    }

    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size()+1, -1);
        ans = max(ans, solve(nums, ans, 0, 0, dp));
        
        return ans;  
    }
};