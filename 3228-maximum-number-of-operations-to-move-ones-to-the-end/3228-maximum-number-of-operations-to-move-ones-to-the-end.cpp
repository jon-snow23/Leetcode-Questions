class Solution {
public:
    int maxOperations(string s) {
        
        int cnt1 = 0;
        int cnt0 = 0;
        int ans = 0;
        int n = s.size();
        
        for(int i=0; i<n-1; i++) {
            if(s[i] == '1' && cnt0>0) {
                ans += cnt1;
                cnt0 = 0;
            }
            
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');
        }
        
        cnt0 += (s[n-1] == '0');
        
        if(cnt0) ans += cnt1;
        return ans;
    }
};