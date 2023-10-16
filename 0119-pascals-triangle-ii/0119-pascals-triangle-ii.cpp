#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1); // Initialize the row with 1s
        
        for (int i = 1; i < rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                // Update the values using the formula: current_value = previous_value + value_above_left
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};
