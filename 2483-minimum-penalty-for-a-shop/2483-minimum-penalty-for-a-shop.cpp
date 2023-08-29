class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            if (ch == 'Y') {
                curPenalty--;  // Reduce penalty for open shop with customers
            } else {
                curPenalty++;  // Increase penalty for closed shop with no customers
            }

            if (curPenalty < minPenalty) {
                earliestHour = i + 1;  // Update the earliest closing hour
                minPenalty = curPenalty;  // Update the minimum penalty
            }
        }

        return earliestHour;
    }
};
