class Solution {
    vector<vector<int>> grid;
    vector<vector<bool>> seen;

private:
    int area(int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || seen[r][c] || grid[r][c] == 0)
            return 0;
        seen[r][c] = true;
        return (1 + area(r+1, c) + area(r-1, c)
                  + area(r, c-1) + area(r, c+1));
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        seen = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(),false));
        int ans = 0;
        for ( int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                ans = max(ans, area(r, c));
            }
        }
        return ans;
    }
};
