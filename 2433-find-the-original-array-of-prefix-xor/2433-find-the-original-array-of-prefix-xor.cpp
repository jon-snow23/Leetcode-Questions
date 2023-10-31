class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        int xor_result = 0;
        
        for (int i = 0; i < pref.size(); ++i) {
            if (i == 0) {
                // For the first element, arr[0] = pref[0].
                arr.push_back(pref[i]);
                xor_result = pref[i];
            } else {
                // For other elements, arr[i] = pref[i] ^ pref[i - 1].
                int current_element = pref[i] ^ xor_result;
                arr.push_back(current_element);
                xor_result ^= current_element;
            }
        }
        
        return arr;
    }
};
