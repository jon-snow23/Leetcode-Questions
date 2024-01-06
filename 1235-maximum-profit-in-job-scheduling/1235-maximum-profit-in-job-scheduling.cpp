class Solution {
public:
    int getIdx(vector<vector<int>>& jobs,int endTime){
        int n = jobs.size();
        int l = 0,r = n-1;
        int ans = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(jobs[mid][0]>=endTime){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
             int notInclude = dp[i+1];
             int j = getIdx(jobs,jobs[i][1]);
             cout<<i<<" "<<j<<endl;
             int include = jobs[i][2]+dp[j];
             dp[i] = max(include,notInclude);
        }
        return dp[0];
    }
};