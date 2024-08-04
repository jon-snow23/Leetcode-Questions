class Solution {
public:
    vector<pair<int, vector<int>>> weightedRects;
    long long totalWeight = 0;    
    Solution(vector<vector<int>>& rects) {
        for (auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalWeight += area;
            weightedRects.push_back(make_pair(area, rect));
        }
    }    
    vector<int> pick() {
        int weight = rand() % (totalWeight + 1);
        for (auto& entry : weightedRects) {
            if (weight <= entry.first) {
                auto& rect = entry.second;
                int px = rect[0] + rand() % (rect[2] - rect[0] + 1);
                int py = rect[1] + rand() % (rect[3] - rect[1] + 1);
                return {px, py};
            }
            weight -= entry.first;
        }
        return {};
    }
};