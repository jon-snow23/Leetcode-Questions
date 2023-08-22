class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        char col1 = s[0];
        char col2 = s[3];
        int row1 = s[1] - '0';
        int row2 = s[4] - '0';
        for (char col = col1; col <= col2; col++) {
            for (int row = row1; row <= row2; row++) {
                string cell = string(1, col) + to_string(row);
                result.push_back(cell);
            }
        }
        
        return result;
    }
};
