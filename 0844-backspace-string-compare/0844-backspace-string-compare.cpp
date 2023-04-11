class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string S) {
        stack<char> ans;
        for (char c : S) {
            if (c != '#')
                ans.push(c);
            else if (!ans.empty())
                ans.pop();
        }
        string result;
        while (!ans.empty()) {
            result += ans.top();
            ans.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};