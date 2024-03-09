class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 1 and nums2.size()==1 and nums1[0] == nums2[0]) return nums1[0];
        int point1 = 0;
        int point2 = 0;
        
        while(point1<nums1.size() and point2<nums2.size()) {
            if(nums1[point1] < nums2[point2]) point1++;
            else if(nums1[point1] > nums2[point2]) point2++;
            else if(nums1[point1] == nums2[point2]) return nums1[point1];
        }
        return -1;
    }
};