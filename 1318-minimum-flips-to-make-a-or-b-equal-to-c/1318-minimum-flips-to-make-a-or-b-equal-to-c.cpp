class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        // Iterate through each bit of a, b, and c
        for (int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;  // Extract the i-th bit of a
            int bitB = (b >> i) & 1;  // Extract the i-th bit of b
            int bitC = (c >> i) & 1;  // Extract the i-th bit of c
            
            if ((bitA | bitB) != bitC) {
                // Flips needed
                if (bitC == 1) {
                    // Flip a and b individually if the i-th bit of c is 1
flips += (bitA == 0 && bitB == 0) ? 1 : 0;
                } else {
                    // Flip a and b individually if the i-th bit of c is 0
                    flips += (bitA == 1) + (bitB == 1);
                }
            }
        }
        
        return flips;
    }
};
