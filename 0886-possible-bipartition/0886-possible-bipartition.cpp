class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto &d: dislikes){
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;

            color[i] = 1;
            q.push(i);

            while(!q.empty()){
                int u = q.front();q.pop();

                for(auto &v: adj[u]){
                    if(color[v]==-1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u]){
                        return false;
                    }
                }

            }   
        }
        return true;
    }
};
