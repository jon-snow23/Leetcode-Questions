#include <string>
#include <algorithm>

class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        string consonants;
        
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels += ch;
            } else {
                consonants += ch;
            }
        }
        sort(vowels.begin(), vowels.end());
        string result;
        int vowelIndex = 0;
        int consonantIndex = 0;
        
        for (char ch : s) {
            if (isVowel(ch)) {
                result += vowels[vowelIndex++];
            } else {
                result += consonants[consonantIndex++];
            }
        }
        
        return result;
    }

private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch =='A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};
