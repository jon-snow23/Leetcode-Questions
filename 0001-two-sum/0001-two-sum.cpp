// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size() , l ,k ;
//         if (n==2) {
//             if (nums[0]+nums[1]==target) {
//                  l = 0 ;k = 1;
//             }
//         }
//         else {for(int i = 0;i < n-1 ;i++) {
//             for (int j = i+1; j<n ;j++) {
//                 if (nums[i]+nums[j]==target) {
//                     l = i ;
//                     k = j ;
//                     break ;
//                 }
//             }
//         } }
//         vector <int> v;
//         v.push_back(l) ;  v.push_back(k);
//             return v;
//     }
// };
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>ans; int i  = 0 ; 
//         while(i<nums.size())
//         {    
//             int j = i+1;
//             while(j<nums.size())
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     break;
//                 }
//                 j++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

































class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int > mp ;
        for(int i = 0 ; i< n ; i++ ) {
            int c = target - nums[i];
            if(mp.find(c) != mp.end()) {
                return { mp[c] , i };
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};


























