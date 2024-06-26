class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0, total = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2) rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty()) {
            int s = rotten.size();
            cnt += s;

            while (s--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                    }
                }
            }

            if (!rotten.empty()) time++;
        }
        return total == cnt ? time : -1;
    }
};
