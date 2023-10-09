class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 , n = nums.size(),high = n-1 , index1 = -1;
        vector<int>v;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if (nums[mid]==target) {index1 = mid ; high = mid - 1;}
            if (nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        v.push_back(index1);
        low = 0 ; n = nums.size(); high = n-1 ;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if (nums[mid]==target) { index1 = mid; low = mid - 1 ; }
            if (nums[mid]>target) high = mid-1;
            else low = mid+1 ;
        }
        v.push_back(index1);
        return v;
        
    }
};