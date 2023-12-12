class Solution {
public:
    int maxProduct(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            nums[i] = nums[i]-1;
        }
        sort(nums.begin() , nums.end(),greater<int>()) ;
        return nums[1]*nums[0];
    }
};