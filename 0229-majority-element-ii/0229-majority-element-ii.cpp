class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int number1=INT_MIN,number2=INT_MIN,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==number1){
                count1++;
            }
            else if(nums[i]==number2){
                count2++;
            }
            else if(count1==0){
                count1=1;
                number1=nums[i];
            }
            else if(count2==0){
                count2=1;
                number2=nums[i];
            }
            else{
                count1--;
                count2--;
            }            
        }
        vector<int>ans; int ss=0; int pb=0;
        for(int i=0; i<n;i++){
            if(nums[i]==number1){
                ss++;
            }
            if(nums[i]==number2){
                pb++;
            }
        }
        if(ss>(n/3)){
            ans.push_back(number1); 
        }
        if(pb>(n/3)){
            ans.push_back(number2);
        }
        return ans;
    }
};