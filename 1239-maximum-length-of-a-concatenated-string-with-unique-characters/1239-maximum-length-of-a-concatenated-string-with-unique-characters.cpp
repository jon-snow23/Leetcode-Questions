class Solution {
public:
    bool comp(string curr, string str) {
        int bitmask = 0;
        for (auto i : curr)
            bitmask |= (1 << (i - 'a'));
        for (auto i : str) {
            int index = i - 'a';
            if (bitmask & (1 << index))
                return false;
            bitmask |= (1 << index);
        }
        return true;
    }
    int find(int n, string curr, vector <string> &arr, unordered_map <string, int> &mp){
        if(n<0) return 0;
        if(mp.find(curr)!=mp.end()) return mp[curr];

        int nottake = find(n-1, curr, arr, mp) + 0;
        int take{};
        if(comp(curr, arr[n]))
            take = find(n-1, curr+arr[n], arr, mp) + arr[n].size();
        
        return mp[curr] = max(take, nottake);
    }
    int maxLength(vector<string>& arr) {
        unordered_map <string, int> mp;
        return find(arr.size()-1, "", arr, mp);
    }
};