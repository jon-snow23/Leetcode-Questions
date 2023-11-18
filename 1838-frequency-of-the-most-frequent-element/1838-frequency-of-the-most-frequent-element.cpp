class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        long sum = 0;
        long curr = 0;
        int start = 0;

        sort(nums.begin(), nums.end());

        for(int end = 0; end < nums.size(); end++){
            curr = nums[end];
            sum += nums[end];

            while((end-start+1) * curr - sum > k){
                sum -= nums[start];
                start++;
            }

            ans = max(ans, (end-start+1));
            // cout<<ans<<endl;
        }

        return ans;
    }
};