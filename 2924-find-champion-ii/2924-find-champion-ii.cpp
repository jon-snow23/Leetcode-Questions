class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int champ= -1;
        vector<int> indegree(n,0);
        for (auto val: edges){
            indegree[val[1]]++;
        }
        for (int i=0; i<n; i++){
            if (indegree[i]== 0){
                if (champ!= -1)return -1;
                champ= i;
            }
        }
        return champ;
    }
};
