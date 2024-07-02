class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> output;
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] == nums2[j]) {
                output.push_back(nums1[i]);
                i--;
                j--;
            } else if (nums1[i] > nums2[j]) {
                i--;
            } else {
                j--;
            }
        }

        return output;
    }
};