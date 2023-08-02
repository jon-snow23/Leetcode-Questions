//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
       int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
        if (A[0][0] == 0) {
            return -1;
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cell = q.front();
                q.pop();

                int x = cell.first;
                int y = cell.second;

                if (x == X && y == Y) {
                    return steps;
                }

                for (auto& direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];

                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] == 1 && !visited[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends