class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long ans=0;long f=0;long c1=0;long c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<target[i])
            {
                long re=target[i]-nums[i];
                if(re>c1)
                {
                    ans=ans+re-c1;
                }
                c1=re;
                c2=0;

            }
            else if(nums[i]>target[i])
            {
                long re=nums[i]-target[i];
                if(re>c2)
                {
                    ans=ans+re-c2;
                }
                c2=re;
                c1=0;
            }
            else if(nums[i]==target[i])
            {
                c1=0;
                c2=0;
            }
        }
        return ans;
        
    }
};