class Solution {
public:
    void bfs(int val,vector<vector<int>>& rooms,vector<int>&vis){
        vis[val]=1;
        queue<int>q;
        q.push(val);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        bfs(0,rooms,vis);
        for(int i=0;i<vis.size();i++) if(!vis[i]) return false;
        return true;
    }
};