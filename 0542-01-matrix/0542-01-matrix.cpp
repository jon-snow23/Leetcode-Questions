class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size();
        vector<vector<int>>vis( n , vector<int>(m,0));
        vector<vector<int>>dis( n , vector<int>(m,0));
        queue<pair<pair<int,int> , int>>q;
        for (int i = 0 ; i <n ; i++) {
            for(int j = 0 ; j<m ;j++) {
                if (mat[i][j]==0) {
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
                else {
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dis[row][col] = step;
            
            int delrow[] = {-1 , 0 , 1 , 0};
            int delcol[] = {0 , 1 , 0 , -1};
            
            for(int i = 0 ; i < 4 ; i++) {
                int ncol = delcol[i] + col;
                int nrow = delrow[i] + row;
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol} , step+1});
                }
            }
        }
        return dis;
    }
};