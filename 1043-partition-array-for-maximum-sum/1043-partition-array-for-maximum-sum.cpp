class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[501]={};
        for(int i=n-1;i>=0;i--){
            int temp=0;
            int ans=0;
            
            for(int j=i;j<min(n,i+k);j++){
               temp=max(temp,arr[j]);
                 
                ans=max(ans,temp*(j-i+1)+dp[j+1]);
            }
            dp[i]=ans;
        }
        
       return dp[0]; 
    }
};