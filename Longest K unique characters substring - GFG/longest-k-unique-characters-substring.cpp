//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        unordered_map<char, int> charCount; // To store character frequency
        int maxLength = -1; 
        int left = 0;

        for (int right = 0; right < n; ++right) {
            charCount[s[right]]++;
while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            // Update maxLength whenever a valid substring is found
            if (charCount.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends