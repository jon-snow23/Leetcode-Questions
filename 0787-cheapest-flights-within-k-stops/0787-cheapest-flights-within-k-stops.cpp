class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int ,int >>adj[n];
        for (auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        // stops , node , distance 
        queue<pair<int , pair <int , int >>>q;
        
        q.push({0 , {src , 0 }});
        vector<int>dist(n, INT_MAX);
        dist[src] = 0 ;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            
            if(stop>k) continue ;
            
            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;
                
                if (edW+dis< dist[adjNode] and stop<=k) {
                    dist[adjNode] = edW+dis;
                    
                    q.push({stop+1 , {adjNode , edW+dis}});
                }
                
            }
        }
        if (dist[dst]==INT_MAX) return -1;
        
        return dist[dst];
    }
};