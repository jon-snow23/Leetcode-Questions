class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==1 && dungeon[0].size()==1)
        return -min(0, dungeon[0][0]) + 1;
        vector<vector<int>> vec(dungeon.size(), vector<int> (dungeon[0].size(), INT_MAX));
        // SORRY
        return -min(max(recurse(dungeon, vec, 1,0), recurse(dungeon, vec, 0,1)) + dungeon[0][0], 0) + 1;
    }

    int recurse(vector<vector<int>>& dungeon, vector<vector<int>> &vec, int i, int j) {
        if(i==dungeon.size() || j == dungeon[0].size())
        return -INT_MAX;

        if(vec[i][j] != INT_MAX) {
            return vec[i][j];
        }

        int cur = max(recurse(dungeon, vec, i+1, j), recurse(dungeon, vec, i, j+1));

        if(cur == -INT_MAX)
        cur = 0;

        vec[i][j] = min(0, cur+dungeon[i][j]);
        return vec[i][j];
    }
};