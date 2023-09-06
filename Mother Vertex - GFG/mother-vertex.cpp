//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void DFS(int v, vector<int> adj[], vector<bool> &visited)
    {
        visited[v] = true;
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                DFS(u, adj, visited);
            }
        }
    }
    int findMotherVertex(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        int potentialMother = -1;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, visited);
                potentialMother = i;
            }
        }
        fill(visited.begin(), visited.end(), false);
        DFS(potentialMother, adj, visited);
        for (bool visit : visited)
        {
            if (!visit)
                return -1; 
        }

        return potentialMother; 
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends