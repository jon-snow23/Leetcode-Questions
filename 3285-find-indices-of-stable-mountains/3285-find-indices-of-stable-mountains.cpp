class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int t) {
        vector<int> si;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > t) {
                si.push_back(i);
            }
        }
        return si;
    }
};
