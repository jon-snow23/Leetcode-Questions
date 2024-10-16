#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;

        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            map<int, int> freq;
            for (int num : subarray) {
                freq[num]++;
            }
            vector<pair<int, int>> freq_vec;
            for (auto& p : freq) {
                freq_vec.push_back(p);
            }
            sort(freq_vec.begin(), freq_vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
                if (a.second == b.second) {
                    return a.first > b.first; 
                }
                return a.second > b.second;
            });
            int sum = 0;
            int count = 0;
            for (auto& p : freq_vec) {
                if (count == x) break;
                sum += p.first * p.second;
                count++;
            }

            answer.push_back(sum);
        }

        return answer;
    }
};
