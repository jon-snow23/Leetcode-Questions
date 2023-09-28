//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // First, perform a DFS to mark all land cells that are connected to the boundary
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    // If it's a land cell on the boundary, start DFS to mark connected land cells
                    markConnectedLand(grid, i, j);
                }
            }
        }

        // Now, count the remaining land cells that are not connected to the boundary
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    void markConnectedLand(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }

        // Mark the current land cell as visited
        grid[x][y] = 0;

        // Visit adjacent land cells in all four directions
        markConnectedLand(grid, x - 1, y);
        markConnectedLand(grid, x + 1, y);
        markConnectedLand(grid, x, y - 1);
        markConnectedLand(grid, x, y + 1);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends