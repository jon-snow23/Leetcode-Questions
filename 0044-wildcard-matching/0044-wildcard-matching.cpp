class Solution {
public:
    bool helper(string &s, string &p, int i, int j,vector<vector<int>> &dp) {
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(i==s.size()){
            while(j < p.size()){
                if(p[j++] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j]=helper(s, p, i + 1, j + 1,dp);
        } else if (p[j] == '*') {
            return dp[i][j]=helper(s, p, i + 1, j,dp) || helper(s,p,i,j+1,dp);
        } else {
            return dp[i][j]=false;
        }
        
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(s, p, 0, 0,dp);
    }
};