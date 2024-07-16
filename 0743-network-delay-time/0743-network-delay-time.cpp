class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        vector<int> timeArr(n+1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0; i<times.size(); i++) {
            int x = times[i][0];
            int y = times[i][1];
            int t = times[i][2];
            adj[x].push_back({y, t});
        }
        timeArr[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            
            int time = temp[0];
            int node = temp[1];
            
            for(vector<int> i: adj[node]) {
                if(timeArr[i[0]] > time + i[1]) {
                    pq.push({i[1] + time, i[0]});
                    timeArr[i[0]] = i[1] + time;
                }
            }
        }
        int minTime = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(timeArr[i] == INT_MAX) return -1;
            minTime = max(minTime, timeArr[i]);
        }
        return minTime;
    }
};