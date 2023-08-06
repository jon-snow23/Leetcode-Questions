//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Helper function to generate permutations recursively
    void generatePermutations(string s, int start, vector<string>& result) {
        if (start == s.length() - 1) {
            result.push_back(s);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // Swap the characters to generate new permutations
            swap(s[start], s[i]);
            generatePermutations(s, start + 1, result);
            // Backtrack by swapping again
            swap(s[start], s[i]);
        }
    }

    vector<string> permutation(string S) {
        vector<string> result;
        generatePermutations(S, 0, result);
        sort(result.begin(), result.end()); // Sort the permutations lexicographically
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends