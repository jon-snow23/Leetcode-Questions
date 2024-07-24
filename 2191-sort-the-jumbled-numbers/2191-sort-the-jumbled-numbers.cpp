#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Function to map a number using the given mapping
        auto getMappedValue = [&mapping](int num) {
            string str = to_string(num);
            for (char& ch : str) {
                ch = '0' + mapping[ch - '0'];
            }
            return stoi(str);
        };
        
        // Create a vector of tuples where first is the mapped value, second is the original value, and third is the original index
        vector<tuple<int, int, int>> mappedNums;
        for (int i = 0; i < nums.size(); ++i) {
            mappedNums.emplace_back(getMappedValue(nums[i]), nums[i], i);
        }
        
        // Sort based on the mapped value while maintaining relative order of same mapped values by original index
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const auto& a, const auto& b) {
            if (get<0>(a) == get<0>(b)) {
                return get<2>(a) < get<2>(b);
            }
            return get<0>(a) < get<0>(b);
        });
        
        // Extract the sorted original numbers
        vector<int> result;
        for (auto& tuple : mappedNums) {
            result.push_back(get<1>(tuple));
        }
        
        return result;
    }
};
