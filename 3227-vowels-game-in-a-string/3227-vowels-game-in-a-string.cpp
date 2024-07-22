class Solution {
public:
    bool doesAliceWin(string s) {
        int countOfvowels=0;
        for(int i=0 ; i<s.size() ; ++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                countOfvowels++;
            }
        }
        if(countOfvowels==0){
            return false;
        }else{
            return true;
        }
    }
};