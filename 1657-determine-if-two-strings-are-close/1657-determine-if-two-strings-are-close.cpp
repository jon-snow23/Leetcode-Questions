class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;

        multiset<int> m1,m2;

        map<char,int> mp1,mp2;

        for(int i=0;i<word1.length();i++) {
            if(!mp2[word1[i]]) {
                int c = count(word2.begin(),word2.end(),word1[i]);
                if(c==0) return false;
                m2.insert(c);
                mp2[word1[i]]=true;
            }

            if(!mp1[word1[i]]) {
                int c = count(word1.begin(),word1.end(),word1[i]);
                m1.insert(c);
                mp1[word1[i]]=true;
            }
        }

        return m1==m2;
    }
};