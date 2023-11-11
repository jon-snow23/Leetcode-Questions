class Graph {
public:
    vector<pair<int,int>> adj[100];
    int size;
    Graph(int n, vector<vector<int>>& edges) {
        size = n;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});   
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(size,1e9);
        dist[node1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    //{dist, node}
        pq.push({0,node1});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dis+edW < dist[adjNode]){
                    dist[adjNode] = dis+edW;
                    pq.push({dis+edW, adjNode});
                }
            }
        }

        if(dist[node2]==1e9)
            return -1;
        return dist[node2];
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */