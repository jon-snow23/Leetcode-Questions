class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        q.push({0, {0, 0}});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == n - 1 && col == m - 1)
                return dis + 1;
            
            int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
            
            for (int i = 0; i < 8; i++) {
                int newR = dr[i] + row;
                int newC = dc[i] + col;
                
                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                    grid[newR][newC] == 0 && !visited[newR][newC]) {
                    q.push({dis + 1, {newR, newC}});
                    visited[newR][newC] = true;
                }
            }
        }
        
        return -1;
    }
};
