class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int ad : adj[node]) {
            if (!vis[ad]) {
                dfs(ad, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adjLs);
            }
        }
        
        return cnt;
    }
};
