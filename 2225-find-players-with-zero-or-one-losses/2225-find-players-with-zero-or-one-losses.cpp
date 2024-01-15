class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto it : matches){
           if(mp.find(it[0]) == mp.end()) mp[it[0]]=0;
            mp[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it : mp){
            if(it.second == 0) ans[0].push_back(it.first);
            if(it.second == 1) ans[1].push_back(it.first);
        }
        return ans;
    }
};