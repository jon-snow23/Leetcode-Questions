class Solution {
public:
    int solve(string& s, int pos, int n, vector<int>& dp){
        if(pos == n){
            return 1;
        }
        if(pos > n || s[pos] == '0'){
            return 0;
        }
        if(dp[pos] != -1){
            return dp[pos];
        }
        int ans = 0;
        if(pos + 1 < n && (s[pos] == '1' || s[pos] == '2')){
            if(!(s[pos] == '2' && ( s[pos + 1] - '0') > 6)){
                ans += solve(s, pos + 2, n, dp);
            }
        }
        ans += solve(s, pos + 1, n, dp); 
        dp[pos] = ans;
        return ans;
        
    }
    int numDecodings(string s) {
        vector<int> dp(1000, -1);
        return solve(s, 0, s.length(), dp);
    }
};