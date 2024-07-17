class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int,vector<int>> adj; 
        vector<int> inDegree(n, 0); 
        for (const auto& pair : richer) {
            adj[pair[0]].push_back(pair[1]);
            inDegree[pair[1]]++;
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = i;
        }
        // Topo sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                // If the current node u's quietest person is quieter than v's current quietest person, update it
                if (quiet[res[u]] < quiet[res[v]]) {
                    res[v] = res[u];
                }
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return res;
    }
};
