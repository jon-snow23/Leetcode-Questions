class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 ;  int temp = 0 ;
        for(auto it : nums) {
              if(it==1) {
                  temp++; if(temp>=ans) ans=temp;
              }
              else {
                  temp = 0 ;
              }
        }
        return ans;
    }
};