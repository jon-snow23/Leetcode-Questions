class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        
        auto dfs = [&](int source, int target, unordered_set<int>& seen, auto& dfs_ref) -> bool {
            if (source == target) return true;
            seen.insert(source);
            for (int nei : graph[source]) {
                if (seen.find(nei) == seen.end() && dfs_ref(nei, target, seen, dfs_ref)) {
                    return true;
                }
            }
            return false;
        };

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            unordered_set<int> seen;
            if (graph.count(u) && graph.count(v) && dfs(u, v, seen, dfs)) {
                return {u, v};
            }
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        return {};
    }
};
