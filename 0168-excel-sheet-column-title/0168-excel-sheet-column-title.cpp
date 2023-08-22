class Solution {
public:
    string convertToTitle(int c) {
        string ans;
        
        while (c) {
            c--;
            ans = ans + (char)((c) % 26 + 'A');
            c = (c) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};