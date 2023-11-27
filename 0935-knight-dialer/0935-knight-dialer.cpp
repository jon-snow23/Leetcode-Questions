#define mod 1000000007

class Solution {
public:
    int knightDialer(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        if (n > 6) {
            int v1, v2, v3, v4, v5;
            v4 = 46;
            v3 = 104;
            v2 = 240;
            v1 = 544;
            for (int i = 7; i <= n; i++) {
                int v0 = (6LL * v2 - 4LL * v4) % mod;
                if (v0 < 0) v0 += mod;
                v4 = v3;
                v3 = v2;
                v2 = v1;
                v1 = v0;
            }
            return v1;
        } else {
            if (n == 1) return 10;
            if (n == 2) return 20;
            if (n == 3) return 46;
            if (n == 4) return 104;
            if (n == 5) return 240;
            if (n == 6) return 544;
        }
        return -1;
    }
};