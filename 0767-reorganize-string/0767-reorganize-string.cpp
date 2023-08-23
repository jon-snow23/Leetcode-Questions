class Solution {
public:
    string reorganizeString(string s) {
        vector<int> characterCounts(26, 0);
        for (char c : s) {
            characterCounts[c - 'a']++;
        }
        int maxCharacterCount = 0, mostFrequentCharacter = 0;
        for (int i = 0; i < characterCounts.size(); i++) {
            if (characterCounts[i] > maxCharacterCount) {
                maxCharacterCount = characterCounts[i];
                mostFrequentCharacter = i;
            }
        }
        if (maxCharacterCount > (s.length() + 1) / 2) {
            return "";
        }
        string result = s;
        int index = 0;
        while (characterCounts[mostFrequentCharacter] != 0) {
            result[index] = char(mostFrequentCharacter + 'a');
            index += 2;
            characterCounts[mostFrequentCharacter]--;
        }
        for (int i = 0; i < characterCounts.size(); i++) {
            while (characterCounts[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                result[index] = char(i + 'a');
                index += 2;
                characterCounts[i]--;
            }
        }
        return result;
    }
};
