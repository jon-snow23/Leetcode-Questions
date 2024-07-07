class Solution {
public:
    int numWaterBottles(int n, int e) {
        int count  = n ;
        while(n/e!=0) {
            int n1 = n/e; int n2 = n%e;
            n = n1+n2;
            count+=n1;
        }
        return count;
    }
};