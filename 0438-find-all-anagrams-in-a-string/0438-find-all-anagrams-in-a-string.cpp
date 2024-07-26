class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        unordered_map<char, int> pCount, sCount;
        for (char c : p) pCount[c]++;
        int windowSize = p.size();
        for (int i = 0; i < windowSize; ++i) {
            sCount[s[i]]++;
        }
        if (pCount == sCount) result.push_back(0);
        for (int i = windowSize; i < s.size(); ++i) {
            sCount[s[i]]++;
            sCount[s[i - windowSize]]--;
            if (sCount[s[i - windowSize]] == 0) {
                sCount.erase(s[i - windowSize]);
            }
            if (pCount == sCount) result.push_back(i - windowSize + 1);
        }

        return result;
    }
};
