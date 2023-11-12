class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target)
            return 0;
        
        unordered_map<int, vector<int>> stopToRoutes;
        unordered_map<int, bool> visited;
        
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
                visited[stop] = false;
            }
        }
        
        queue<int> q;
        q.push(source);
        
        int ans = 1;
        unordered_set<int> seenRoutes;
        
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                int currentStop = q.front();
                q.pop();
                
                for (int route : stopToRoutes[currentStop]) {
                    if (seenRoutes.count(route))
                        continue;
                    
                    seenRoutes.insert(route);
                    for (int stop : routes[route]) {
                        if (stop == target)
                            return ans;
                        if (!visited[stop]) {
                            q.push(stop);
                            visited[stop] = true;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};