class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>st;
        int i=1;
        while(st.size()<n)
        {
            if(st.count(k-i))
            {
                i++;
                continue;
            }
            st.insert(i);
            i++;
        }
        int sum=0;
        for(auto it:st)sum+=it;
        return sum;
    }
};