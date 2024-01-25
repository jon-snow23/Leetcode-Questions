class Solution {
private:
    int solveMemo(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
        //base case
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(text1[i]==text2[j]){
            dp[i][j]=solveMemo(i-1,j-1,text1,text2,dp)+1;
        }
        else{
            dp[i][j]=max(solveMemo(i-1,j,text1,text2,dp),solveMemo(i,j-1,text1,text2,dp));
        }
        return dp[i][j];
    }

    int solveTab(string &text1,string &text2){
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    if(i-1>=0 && j-1>=0){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                }
                else{
                    if(i>0 && j>0){
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        // return solveMemo(text1.size()-1,text2.size()-1,text1,text2,dp);

        return solveTab(text1,text2);
    }
};