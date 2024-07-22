int init = [](){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return -1;
}();

class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int a = ((n >> i) & 1), b = ((k >> i) & 1);
            if(a == b) continue;
            if(a == 0 && b == 1) return -1;
            ans++;
        }
        return ans;
    }
};