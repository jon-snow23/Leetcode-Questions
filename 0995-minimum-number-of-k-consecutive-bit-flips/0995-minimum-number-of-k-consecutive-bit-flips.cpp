class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int len=nums.size(),ans=0,currCount=0,currRange;
        queue<int> rangeCount;
        
        for(int index=0;index<nums.size();index++) {
            while(rangeCount.size()>0 && rangeCount.front()<index) {
                currCount--;
                rangeCount.pop();
            }
            
            nums[index]=currCount%2==0?nums[index]:nums[index]^1;
            if(nums[index]==1)
                continue;
            if(nums[index]==0 && index+k-1>=len)
                return -1;
            nums[index]=1;
            ans++;
            currRange=index+k-1;
            currCount++;
            rangeCount.push(currRange);
        }
        
        
        return ans;
    }
};