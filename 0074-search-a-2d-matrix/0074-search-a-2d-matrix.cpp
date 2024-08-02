class Solution {
    bool binarySearch(vector<int> &nums, int target){
        int s = 0, e = nums.size()-1;

        int mid = s+(e-s)/2;

        while(s<=e){
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool ans = false;

        for(int i=0; i<n; i++){
            if(matrix[i][m-1] >= target){
                ans = binarySearch(matrix[i], target);
                break;
            }
        }

        return ans;
    }
};