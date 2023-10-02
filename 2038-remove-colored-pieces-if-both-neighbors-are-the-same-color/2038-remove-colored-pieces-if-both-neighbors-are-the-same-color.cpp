class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceCount = 0;
        int bobCount = 0;
        int n = colors.size();
        
        // Count consecutive 'A's and 'B's
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
                aliceCount++;
            } else if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') {
                bobCount++;
            }
        }
        
        // Alice wins if she has more valid moves than Bob
        return aliceCount > bobCount;
    }
};
