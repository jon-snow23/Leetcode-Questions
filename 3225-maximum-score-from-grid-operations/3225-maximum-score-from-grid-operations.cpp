typedef long long ll;
class Solution {
public:
int n;
vector<vector<ll>> prefixsum;
    ll getps(int j, int x, int y)
    {
        if (j < 0) return 0;
        x--;
        y--;
        if (x >= y) return 0;
        if (x == -1) return prefixsum[y][j];
        return prefixsum[y][j] - prefixsum[x][j];
    }
    long long maximumScore(vector<vector<int>>& g) {
        n = g.size();
        prefixsum =  vector<vector<ll>>(n, vector<ll>(n, 0));
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                if (i == 0) prefixsum[i][j] = g[i][j];
                 else  prefixsum[i][j] = g[i][j] + prefixsum[i - 1][j];
        }

        // with last row
        vector<ll> dp(n + 1, 0);
        // without last row
        vector<ll> dp1(n + 1, 0);

        // with cur row
        vector<ll> cur(n + 1, 0);
        // without cur row
        vector<ll> cur1(n + 1, 0);
        for (int j = 1; j < n; j++)
        {
           for (int k = 0; k <= n; k++)
           {
                for (int i = 0; i <= n; i++)
                {
                    if (k == i)
                    {
                        cur[i] = max(cur[i], dp[k]);
                        cur1[i] = max(cur1[i], dp[k]);
                    } else if (k < i)
                    {
                        cur[i] = max(cur[i], dp[k]);
                        cur1[i] = max(cur1[i], dp[k]);
                        cur1[i] = max(cur1[i], dp1[k] + getps(j - 1, k, i));
                    } else // k > i
                    {
                        cur[i] = max(cur[i], dp[k] + getps(j, i, k));
                        cur1[i] = max(cur1[i], dp[k]);
                    }
                }
           }

           for (int i = 0; i <= n; i++) cur[i] = max(cur[i], cur1[i]);
           swap(cur, dp);
           swap(cur1, dp1);
        }

        ll ans = 0;
        for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
        
        return ans;
    }
};