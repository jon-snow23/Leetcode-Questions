//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#include <unordered_map>

class Solution {
public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> romanNumerals = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prevValue = 0;
        
        // Traverse the string from right to left
        for (int i = str.size() - 1; i >= 0; --i) {
            int currValue = romanNumerals[str[i]];
            
            // If the current numeral is greater than or equal to the previous numeral, add it to the result
            if (currValue >= prevValue) {
                result += currValue;
            } else {  // If the current numeral is smaller than the previous numeral, subtract it from the result
                result -= currValue;
            }
            
            // Update the previous numeral for the next iteration
            prevValue = currValue;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends