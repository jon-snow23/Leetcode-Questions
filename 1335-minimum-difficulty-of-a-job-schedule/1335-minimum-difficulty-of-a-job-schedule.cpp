class Solution {
public:
    int solver(vector<int>& jobDifficulty, int d,int i,int cur_max,int n, int ans,vector<vector<vector<int>>> &dp){
        if(i==n){
            if(d==0) return 0;
            else return 10000;
        }
        if(dp[i][d][cur_max]!=-1) return dp[i][d][cur_max];
        if(d==0 && i<n) return 10000;
        cur_max=max(cur_max,jobDifficulty[i]);
        ans=min(solver(jobDifficulty, d, i+1,cur_max,n,ans,dp),
            (cur_max+solver(jobDifficulty, d-1, i+1,0,n,ans,dp)));
        dp[i][d][cur_max]=ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            m=max(m,jobDifficulty[i]);
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(d+1,vector<int> (m+1,-1)));
        int ans=0;
        if(d>n) return -1;
        if(d==n){
            for(int i=0;i<n;i++){
                ans+=jobDifficulty[i];
            }
            return ans;
        }
        ans=solver(jobDifficulty, d, 0,0,n,ans,dp);
        return ans;
    }
};