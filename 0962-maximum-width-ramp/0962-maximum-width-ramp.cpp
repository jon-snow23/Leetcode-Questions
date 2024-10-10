class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rmax(n);
        rmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;
        while (right < n) {
            while (left < right && nums[left] > rmax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};