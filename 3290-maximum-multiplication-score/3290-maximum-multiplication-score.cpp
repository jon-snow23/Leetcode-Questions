class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> max1(n, LLONG_MIN);
        vector<long long> max2(n, LLONG_MIN);
        vector<long long> max3(n, LLONG_MIN);
        vector<long long> max4(n, LLONG_MIN);
        for (int i = 0; i < n; i++) {
            max1[i] = (i > 0 ? max1[i-1] : LLONG_MIN);
            max1[i] = max(max1[i], (long long)a[0] * b[i]);
        }
        for (int j = 1; j < n; j++) {
            max2[j] = (j > 1 ? max2[j-1] : LLONG_MIN);
            max2[j] = max(max2[j], max1[j-1] + (long long)a[1] * b[j]);
        }
        for (int k = 2; k < n; k++) {
            max3[k] = (k > 2 ? max3[k-1] : LLONG_MIN);
            max3[k] = max(max3[k], max2[k-1] + (long long)a[2] * b[k]);
        }
        for (int l = 3; l < n; l++) {
            max4[l] = (l > 3 ? max4[l-1] : LLONG_MIN);
            max4[l] = max(max4[l], max3[l-1] + (long long)a[3] * b[l]);
        }
        
        return max4[n-1];
    }
};
