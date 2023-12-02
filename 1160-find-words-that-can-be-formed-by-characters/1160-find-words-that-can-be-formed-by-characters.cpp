#include <unordered_map>
#include <string>

class Solution {
public:
    // Helper function to check if a word can be formed using characters from chars
    bool helper(const string &word, unordered_map<char, int>& charFreq) {
        unordered_map<char, int> wordFreq;

        // Count the frequency of each character in the word
        for (char ch : word) {
            wordFreq[ch]++;
        }

        // Check if the word can be formed using characters from chars
        for (const auto& entry : wordFreq) {
            char ch = entry.first;
            int freq = entry.second;

            // Frequency comparison with chars
            if (charFreq[ch] < freq) {
                return false;
            }
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        // Count how many times each character occurs in string chars
        unordered_map<char, int> charFreq;
        for (char ch : chars) {
            charFreq[ch]++;
        }

        int count = 0;

        // Iterate through words and update the count
        for (const string &word : words) {
            if (helper(word, charFreq)) {
                // If the word can be formed, add its length to the count
                count += word.size();
            }
        }

        // Return the final count
        return count;
    }
};
