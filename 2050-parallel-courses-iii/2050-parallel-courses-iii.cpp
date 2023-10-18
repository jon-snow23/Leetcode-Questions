class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Step 1: Create adjacency list
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (const auto& rel : relations) {
            graph[rel[0]].push_back(rel[1]);
            inDegree[rel[1]]++;
        }
        
        // Step 2: Initialize totalTime array
        vector<int> totalTime(n + 1);
        for (int i = 1; i <= n; ++i) {
            totalTime[i] = time[i - 1];
        }
        
        // Step 3: Perform topological sorting and BFS
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const auto& next : graph[curr]) {
                inDegree[next]--;
                totalTime[next] = max(totalTime[next], totalTime[curr] + time[next - 1]);
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // Step 4: Find maximum time required
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            maxTime = max(maxTime, totalTime[i]);
        }
        
        // Step 5: Return maximum time
        return maxTime;
    }
};
