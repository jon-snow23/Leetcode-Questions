class Solution {
public:

    int counts(vector<vector<int>>&arr,int x,int k){
        int n=arr.size();
        int start=0,end=n-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid][0]>=x)end=mid-1;
            else {
                start=mid+1;
                ans=mid;
            }
        }
        int ans2=-1;
        start=0,end=ans;
         while(start<=end){
            int mid=start+(end-start)/2;
            if(k-arr[mid][1]>=x){
                start=mid+1;
                ans2=mid;
            }
            else {
                end=mid-1;
            }
        }
        // cout<<x<<" ";
        // cout<<ans2<<"| ";
        return ans-ans2;
    }
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr;
        vector<vector<int>>temp;
        // vector<int>temp2;
        unordered_map<int,int>mp;
        for(int i=0;i<(n/2);i++){
            arr.push_back(abs(nums[i]-nums[n-i-1]));
            mp[abs(nums[i]-nums[n-i-1])]++;
            if(nums[i]>nums[n-i-1])swap(nums[i],nums[n-i-1]);
            temp.push_back({nums[n-1-i],nums[i]});
            // temp2.push_back(nums[i]);
            // cout<<arr[i]<<" ";
        }
        int ans=n;
        // reverse(nums.begin9)
        sort(temp.begin(),temp.end());
        int m=temp.size();
        for(int i=0;i<arr.size();i++){
            int x=counts(temp,arr[i],k);
            // cout<<x<<" "<<arr[i]<<"/ ";
            int temp1=(2*x)+(m-x)-mp[arr[i]];
            ans=min(ans,temp1);
        }
        return ans;





        // return 0;
    }
};