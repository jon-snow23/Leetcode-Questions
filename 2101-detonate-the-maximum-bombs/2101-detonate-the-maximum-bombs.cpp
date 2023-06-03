class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size();
        
        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];
                
                // Create a path from node i to node j, if bomb i detonates bomb j.
                if ((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) {
                    graph[i].push_back(j);
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = max(answer, bfs(i, graph));
        }
        
        return answer;
    }
    
private:
    int bfs(int i, unordered_map<int, vector<int>>& graph) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(i);
        visited.insert(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int neib : graph[cur]) {
                if (visited.find(neib) == visited.end()) {
                    visited.insert(neib);
                    q.push(neib);
                }
            }
        }
        return visited.size();
    }
};
