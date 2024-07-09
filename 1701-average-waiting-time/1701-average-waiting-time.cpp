class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        long long wtime = 0;

        for (int i = 0; i < customers.size(); i++) {
            time = max(customers[i][0], time) + customers[i][1];
            wtime += time - customers[i][0];
        }
        double avg = static_cast<double>(wtime) / customers.size();
        return avg;
    }
};