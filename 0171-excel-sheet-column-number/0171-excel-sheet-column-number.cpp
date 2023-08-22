class Solution {
public:
    int titleToNumber(string c) {
        int result = 0;
        for (char c : c) {
            int digitValue = c - 'A' + 1;
            result = result * 26 + digitValue;
        }
        return result;
    }
};
