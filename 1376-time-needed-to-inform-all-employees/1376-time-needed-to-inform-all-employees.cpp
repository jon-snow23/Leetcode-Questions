class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        
        // Create the adjacency list representation of the tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }
        
        return dfs(adjList, informTime, headID);
    }
    
    int dfs(vector<vector<int>>& adjList, vector<int>& informTime, int curEmployee) {
        int maxTime = 0;
        
        for (int subEmployee : adjList[curEmployee]) {
            maxTime = max(maxTime, dfs(adjList, informTime, subEmployee));
        }
        
        return informTime[curEmployee] + maxTime;
    }
};
