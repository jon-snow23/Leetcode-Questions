class Solution {
public:
    void dfs(vector<vector<int>> &vis , int delRow[] , int delCol[] , int sr , int sc , int inColor , int color) {
        vis[sr][sc] = color;
        
        int m = vis.size();
        int n = vis[0].size();
        
        for(int i = 0 ; i<4 ; i++) {
            int row = delRow[i]+sr;
            int col = delCol[i]+sc;
            
            if(row>=0 and row<m and col>=0 and col<n and vis[row][col]==inColor and vis[row][col]!=color) 
                dfs(vis , delRow , delCol , row , col , inColor , color );
        }
        
        
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int inColor = grid[sr][sc];   
        vector<vector<int>>vis = grid;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dfs(vis , delRow , delCol , sr , sc , inColor , color );
        return vis;
    }
};