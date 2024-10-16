class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int left  = 0 ; int right = n-1;
        int leftMax = 0 ; int rightMax = 0;
        int count = 0 ;
        while(left<right) {
            if(nums[left]<nums[right]) {
                if(nums[left]>=leftMax) leftMax = nums[left];
                else count+=leftMax - nums[left];
                left++;
            }
            else {
                if(nums[right]>=rightMax) rightMax = nums[right];
                else count+=rightMax - nums[right];
                right--;
            }
            
        }
        return count;
    }
};
