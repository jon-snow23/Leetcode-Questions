//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>& edges) {
        // Create an adjacency list with V empty vectors.
        vector<vector<int>> adjacencyList(V);

        // Iterate through the given edges and add vertices to the adjacency list.
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;

            // Since it's an undirected graph, add both u to v and v to u.
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }

        return adjacencyList;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends