class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int len = 1;
        int mx = neededTime[0];
        int sum = mx;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(i + 1 < n && colors[i] == colors[i + 1]) {
                len++;
                mx = max(mx , neededTime[i + 1]);
                sum += neededTime[i + 1];
            }
            else if(len > 1) {
                len = 1;
                ans += sum - mx;
                mx = neededTime[i + 1];
                sum = mx;
            }
            else if(i + 1 < n) {
                mx = neededTime[i + 1];
                sum = mx;
            }
        }

        return ans;
    }
};