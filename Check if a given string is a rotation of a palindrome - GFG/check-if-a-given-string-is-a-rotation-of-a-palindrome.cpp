//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    
    while(start < end) {
        if(s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    
    return 1;
}

int isRotatedPalindrome(string s)
{
    int n = s.size();
    string temp = s + s;
    
    for(int i = 0; i < n; i++) {
        string substring = temp.substr(i, n);
        if(isPalindrome(substring)) {
            return 1;
        }
    }
    
    return 0;
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isRotatedPalindrome(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends