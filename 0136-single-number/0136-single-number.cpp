class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once  = 0 ;
        for(auto it : nums) once^=it;
        return once;
    }
};