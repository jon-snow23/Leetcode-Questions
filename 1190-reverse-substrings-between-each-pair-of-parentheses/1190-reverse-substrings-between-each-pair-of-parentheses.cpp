class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for (char it : s) {
            if (it == '(') {
                st.push(res.length());
            } else if (it == ')') {
                int start = st.top();
                st.pop();
                reverse(res.begin() + start, res.end());
            } else {
                res += it;
            }
        }
        return res;
    }
};