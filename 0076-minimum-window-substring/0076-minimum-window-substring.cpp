class Solution {
private:
    int da[26] = {}; 
    int dA[26] = {};
    int d1a[26] = {};
    int d1A[26] = {};
public:
    bool check() {
        // return true;
        for (int i=0; i<26; ++i) {
            if (d1a[i] < da[i]) return false;
            if (d1A[i] < dA[i]) return false;
        }
        return true;
    }

    string minWindow(const string& s, const string& t) {
        int length = 1e5 + 5;
        int minStart = INT_MAX;
        int minEnd = 0;
    
        if (s.size() < t.size()) return "";
        if (s == t) return t;
        for (const char& c : t) {
            if (c >= 'a') ++da[c - 'a'];
            else if (c >= 'A') ++dA[c - 'A'];
        }
        
        int l=0, h=0;
        while (h < s.size()) {
            if (s[h] >= 'a') ++d1a[s[h] - 'a'];
            else if (s[h] >= 'A') ++d1A[s[h] - 'A'];
            
            while (check()) {
                if (h-l+1 < length) {
                    length = h-l+1;
                    minStart = l;
                    minEnd = h;
                }

                if (s[l] >= 'a') --d1a[s[l] - 'a'];
                else if (s[l] >= 'A') --d1A[s[l] - 'A'];
                ++l;
            }
            ++h;
        }
        return minStart == INT_MAX ? "" : s.substr(minStart, minEnd - minStart + 1);
    }
};