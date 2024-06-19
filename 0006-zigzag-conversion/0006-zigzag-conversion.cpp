class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        
        string soln[numRows];
        int r = 0, i = 0;
        while(i < n)
        {
            //Phase 1
            while(i < n)
            {
                soln[r] += s[i];
                i++;
                if(r == numRows - 1)
                    break;
                r++;
            }
            //Phase 2 
            while(i < n && r > 0)
            {
                r--;
                soln[r] += s[i];
                i++;
                if(r == 0){
                    r++;
                    break;
                }
            }
        }
        string val = "";
        for(int i = 0; i < numRows; i++)
        {
            val += soln[i];
        }

        return val;
    }
};