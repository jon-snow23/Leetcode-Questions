class Solution
{
public:
    int calc(int i, int j, vector<vector<int>> &dungeon, map<string, int> &mp)
    {
        if (i >= dungeon.size() || j >= dungeon[0].size())
            return INT_MAX;
        string key = to_string(i) + "key" + to_string(j);
        if (mp.contains(key))
        {
            return mp[key];
        }
        int health = min(calc(i + 1, j, dungeon, mp), calc(i, j + 1, dungeon, mp));

        if (health == INT_MAX)
            health = 1;

        int res = max(health - dungeon[i][j], 1);
        mp.insert({key, res});
        return res;
    }

    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 0;
        map<string, int> mp;
        return calc(0, 0, dungeon, mp);
    }
};