class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            long long numElements = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            answer += numElements - 1;
            nums[i] /= numElements;
        }

        return answer;
    }
};
