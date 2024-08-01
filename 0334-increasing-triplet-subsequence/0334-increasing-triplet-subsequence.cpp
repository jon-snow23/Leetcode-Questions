class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n= nums.size();
        if(n<3){
            return false;
        }
        
        int i=INT_MAX;
        int j=INT_MAX;
        int k=INT_MAX;
        for(int num:nums){
            if(num<=i){
                i=num;
            }
            else if(num<=j){
                j=num;

            }
            else if(num<=k){
                return true;
            }
        }
        return false;
    }
};