class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto k : words) {
            int i = 0, j = 0;
            bool valid = true;

            while (i < s.length() && j < k.length()) {
                if (s[i] != k[j]) {
                    valid = false;
                    break;
                }

                int len1 = 0, len2 = 0;
                char c = s[i];

                while (i < s.length() && s[i] == c) {
                    len1++;
                    i++;
                }
                while (j < k.length() && k[j] == c) {
                    len2++;
                    j++;
                }

                if (len1 < len2 || (len1 > len2 && len1 < 3)) {
                    valid = false;
                    break;
                }
            }
            if (valid && i == s.length() && j == k.length()) ans++;
        }
        return ans;
    }
};