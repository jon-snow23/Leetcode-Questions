class Solution {
public:
    int bfs(vector<vector<int>>& g, int sNode) {
        int n = g.size();
        queue<tuple<int, int, int>> q; // node, steps, path
        q.push({sNode, 0, (1 << sNode)});

        vector<unordered_set<int>> vis(n, unordered_set<int>());
        vis[sNode].insert((1 << sNode));

        while (!q.empty()) {
            int currentNode = get<0>(q.front());
            int steps = get<1>(q.front());
            int path = get<2>(q.front());
            q.pop();

            if (path == (1 << n) - 1)
                return steps;

            for (const int& neigh : g[currentNode]) {
                int newPath = path | (1 << neigh);
                if (!vis[neigh].contains(newPath)) {
                    vis[neigh].insert(newPath);
                    q.push({neigh, steps+1, newPath});
                }
            }
        }
        return INT_MAX;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            ans = min(ans, bfs(graph, i));
        return ans;
    }
};