class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair <int , pair<int ,int>>, 
        vector<pair<int , pair<int , int>>>, 
        greater<pair<int , pair <int , int >>>>pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n , vector<int>( m , INT_MAX));
        
        dist[0][0] = 0 ; 
        pq.push({0 , {0,0}});
        
        int dr[] = {-1 , 0 , 1 , 0};
        int dc[] = {0 , 1 , 0 , -1};
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row==n-1 and col==m-1) return diff;
            
            for(int i = 0 ; i <4 ; i++) {
                int newR = row+dr[i];
                int newC = col+dc[i];
                
                if (newR>=0 and newR<n and newC>=0 and newC<m) {
                    int newEffort = max(abs (heights[row][col] - heights[newR][newC]) , diff);
                    
                    if (newEffort < dist[newR][newC]) {
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort , {newR , newC}});
                    }
                }
            }
        }
        return 0;
    }
};