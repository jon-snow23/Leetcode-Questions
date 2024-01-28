class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int count = 0;
        queue<pair<int, int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis( n , vector<int>( m , 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (mat[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delrow[] = {-1 , 0 , 1 , 0};
            int delcol[] = {0 , 1 , 0 , -1};
            
            for (int i = 0 ; i<4 ; i++) {
                int nrow = delrow[i]+row;
                int ncol = delcol[i]+col;
                if (ncol>=0 and ncol<m and nrow>=0 and nrow<n and !vis[nrow][ncol] and mat[nrow][ncol]==1) {
                    vis[nrow][ncol]=1;
                    q.push({nrow , ncol});
                }
            }
        }
        
        for(int i = 0 ; i < n; i++) {
            for (int j  = 0 ; j< m ; j++) {
                if(mat[i][j]==1 and vis[i][j]==0) {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};