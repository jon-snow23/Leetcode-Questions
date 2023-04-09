class Solution {
public:
    vector<long long> distance(vector<int>& v) {
        unordered_map<int, vector<long long>> mps;
        unordered_map<int, vector<int>> mi;
        int n = v.size();
        for(int i = 0; i < n; ++i) {
            int x = v[i];
            if(!mps.count(x)) mps[x].push_back(0);
            mps[x].push_back(mps[x].back() + (long long)i + 1);
            mi[x].push_back(i);
        }
        vector<long long> ans(n);
        for(int i = 0; i < n; ++i) {
            int x = v[i];
            int idx = lower_bound(mi[x].begin(), mi[x].end(), i + 1) - mi[x].begin();
            long long left = idx, right = mi[x].size() - idx;
            long long iPlusOne = i + 1LL;
            ans[i] = left * iPlusOne - mps[x][left - 1] + mps[x].back() - mps[x][left] - (right + 1LL) * iPlusOne;
        }
        return ans;
    }
};