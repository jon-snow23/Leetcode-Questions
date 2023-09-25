//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> result;
        priority_queue<pair<int, pair<int, int>>> pq; // Min-heap
        set<pair<int, int>> usedIndices;

        // Sort arrays A and B in non-decreasing order
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // Push the initial sum (largest elements from both arrays)
        pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
        usedIndices.insert({N - 1, N - 1});

        while (K > 0) {
            // Pop the smallest sum combination
            auto curr = pq.top();
            pq.pop();

            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            result.push_back(sum);
            K--;

            // Add the next possible combinations
            if (i > 0 && usedIndices.find({i - 1, j}) == usedIndices.end()) {
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                usedIndices.insert({i - 1, j});
            }
            if (j > 0 && usedIndices.find({i, j - 1}) == usedIndices.end()) {
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                usedIndices.insert({i, j - 1});
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends