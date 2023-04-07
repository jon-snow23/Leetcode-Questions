class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        
        // Iterate from the second last row to the top row
        for (int i = n - 2; i >= 0; i--) {
            // Update each element in the current row with the minimum sum
            // of the two adjacent numbers in the row below
            for (int j = 0; j <= i; j++) {
                // For each element, add the minimum of the element below and to the right
                // to avoid redundant calculations
                t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
            }
        }
        
        // The minimum path sum will be stored in the top element of the triangle
        return t[0][0];
    }
};