class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> op;
    for (const string& log : logs) {
        if (log == "./") {
        } else if (log == "../") {
            if (!op.empty()) {
                op.pop();
            }
        } else {
            op.push(log);
        }
    }

    return op.size();
    }
};
