class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp1,mp2;
        for(int i : arr) mp1[i]++;
        for(auto i : mp1) mp2[i.second]++;
        return mp1.size() == mp2.size();
    }
};