class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) {
            return 0;
        }
        int totalSeconds = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n - 1; i++) {
            totalSeconds += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        totalSeconds += duration;

        return totalSeconds;
    }
};
