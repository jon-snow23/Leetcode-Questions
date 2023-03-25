class Solution {
public:
    int merge(vector<int>&nums,int lo , int mid , int hi){
        int cnt=0;
        int j = mid+1;
        for(int i=lo;i<=mid;i++ ){
            while(j<=hi && nums[i] > 2LL*nums[j])j++;

            cnt+=(j-(mid+1));
        }
        vector<int> temp;

        int left = lo;
        int rig = mid+1;

        while(left<=mid && rig <=hi){
            if(nums[left]<nums[rig]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[rig++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }

        while(rig<=hi){
            temp.emplace_back(nums[rig++]);
        }

        for(int i = lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
        return cnt;
    }

    int mergesort(vector<int>&nums,int lo , int hi){
        if(lo>=hi)return 0;
        int mid = (lo+hi)/2;
        int inv = mergesort(nums,lo,mid);
        inv+=mergesort(nums,mid+1,hi);
        inv+=merge(nums,lo,mid,hi);
        return inv;
    }



    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};