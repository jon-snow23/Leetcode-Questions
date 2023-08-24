class Solution {
public:
    string reorderSpaces(string text) {
        int space = count(text.begin(), text.end(), ' ');
        vector<string> words;
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        int wordCount = words.size();
        int res = (wordCount - 1 > 0) ? space / (wordCount - 1) : space;
        string result = "";
        
        for (const string& w : words) {
            result += w;
            
            if (space >= res) {
                result += string(res, ' ');
                space -= res;
            }
        }
        
        if (space > 0) {
            result += string(space, ' ');
        }
        
        return result;
    }
};
