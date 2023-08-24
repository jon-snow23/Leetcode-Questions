class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int idx = 0;
        
        while (idx < words.size()) {
            int lineLength = words[idx].size();
            int wordCount = 1;
            int nextWordIdx = idx + 1;
            
            // Determine words for the current line
            while (nextWordIdx < words.size() && lineLength + words[nextWordIdx].size() + wordCount <= maxWidth) {
                lineLength += words[nextWordIdx].size();
                wordCount++;
                nextWordIdx++;
            }
            
            // Construct the line
            string line = words[idx];
            int extraSpaces = maxWidth - lineLength;
            
            if (wordCount > 1 && nextWordIdx < words.size()) {
                int spacesBetweenWords = extraSpaces / (wordCount - 1);
                int remainderSpaces = extraSpaces % (wordCount - 1);
                
                for (int i = idx + 1; i < nextWordIdx; i++) {
                    line += string(spacesBetweenWords + (remainderSpaces-- > 0 ? 1 : 0), ' ') + words[i];
                }
            } else {
                // For the last line or a line with only one word
                for (int i = idx + 1; i < nextWordIdx; i++) {
                    line += " " + words[i];
                }
                line += string(maxWidth - line.length(), ' ');
            }
            
            result.push_back(line);
            idx = nextWordIdx;
        }
        
        return result;
    }
};
