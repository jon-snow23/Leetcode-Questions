class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int i = 1  ;
        int ans = INT_MIN;
        int low = arr[0][0];
        int high = arr[0][0] ;
        if(arr[0].size() > 1)
            high = arr[0][arr[0].size() -1 ] ;

        while ( i < arr.size() ) {
            int x = 0 ;
            int y = arr[i].size() -1 ;
            int temp = high - arr[i][x];
            ans = max(ans,temp) ;
            temp = high - arr[i][y] ;
            ans = max(ans,temp) ;
            temp = arr[i][x] - high;
            ans = max(ans,temp);
            temp = arr[i][y] - high ;
            ans = max(ans,temp);

            temp = low - arr[i][y] ;
            ans = max(ans,temp) ;
            temp = arr[i][y] -low ;
            ans = max(ans,temp);
            temp = arr[i][x] - low ;
            ans = max(ans,temp) ;
            temp = low - arr[i][x] ;
            ans = max(ans,temp) ;

            low = min(low,arr[i][x]);
            high = max(high,arr[i][y]);
            i++;
        }
        return ans;
    }
};