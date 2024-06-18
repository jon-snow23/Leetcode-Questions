class Solution {
public:
    
    void bfs(vector<vector<char>>& grid , vector<vector<int>>& vis, int row , int col) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc] == '1') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m, 0));
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j =  0; j < m ; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(grid , vis , i , j);
                }
            }
        }
        
        return count;
    }
};
