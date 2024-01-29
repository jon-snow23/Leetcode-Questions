#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                if (a[i][j] != 0) {
                    adj[i].push_back(a[i][j]);
                }
            }
        }
        
        vector<int> color(n, -1);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        } else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
