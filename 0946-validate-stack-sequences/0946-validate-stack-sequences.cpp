class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size();
        stack<int> st;

        int j = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && j < N && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return j == N;
    }
};