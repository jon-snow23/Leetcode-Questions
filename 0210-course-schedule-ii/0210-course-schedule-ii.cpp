class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         vector<int> adj[n];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(n,0);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int>ans;
        int count = 0 ;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (count == n) {
            return ans;
        }
        vector<int>an2;
        return an2;
    }
};