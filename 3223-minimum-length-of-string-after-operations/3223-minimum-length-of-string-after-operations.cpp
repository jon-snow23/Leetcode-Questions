class Solution { 
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int remain = 0;
        for(auto mp : mpp){
            if(mp.second % 2 == 0){
                remain += 2; 
            }
            else if(mp.second % 2 != 0){
                remain += 1;
            }
        }
         return remain;
    }
};