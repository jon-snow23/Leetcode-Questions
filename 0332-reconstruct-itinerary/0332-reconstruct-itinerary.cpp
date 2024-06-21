class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& mp, string s, vector<string>& res) {
        while (!mp[s].empty()) {
            string newNode = *mp[s].begin();
            mp[s].erase(mp[s].begin());
            dfs(mp, newNode, res);
        }
        res.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (int i = 0; i < tickets.size(); ++i) {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> res;
        
        dfs(mp, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};
