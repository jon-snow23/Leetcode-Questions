//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> rotate(int n, int d) {
        vector<int> result(2);
        d %= 16;
        string binaryN = bitset<16>(n).to_string();
        string leftRotated = binaryN.substr(d) + binaryN.substr(0, d);
        string rightRotated = binaryN.substr(16 - d) + binaryN.substr(0, 16 - d);
        result[0] = stoi(leftRotated, nullptr, 2);
        result[1] = stoi(rightRotated, nullptr, 2);
        return result;
    }
};



//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends