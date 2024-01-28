class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }

public:
    void solve(vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] and mat[0][j] == 'O') {
                dfs(0, j, vis, mat);
            }
            if (!vis[n - 1][j] and mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] and mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            if (!vis[i][m - 1] and mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
