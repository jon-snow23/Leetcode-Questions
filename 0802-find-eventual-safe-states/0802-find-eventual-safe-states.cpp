#include <vector>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); 

        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(graph, state, i)) {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& state, int node) {
        if (state[node] == 1) {
            return false; // Found a cycle, not safe
        }

        if (state[node] == 2) {
            return true; // Already determined to be safe
        }

        state[node] = 1; // Mark as visiting

        for (int neighbor : graph[node]) {
            if (!dfs(graph, state, neighbor)) {
                return false; // Not safe if any neighbor is not safe
            }
        }

        state[node] = 2; // Mark as visited and safe
        return true;
    }
};
