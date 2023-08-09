//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long int largestPrimeFactor(int N) {
        long long int largestFactor = -1;

        // Handle the special case of 2 separately
        while (N % 2 == 0) {
            largestFactor = 2;
            N /= 2;
        }

        // Loop through odd prime factors
        for (int i = 3; i * i <= N; i += 2) {
            while (N % i == 0) {
                largestFactor = i;
                N /= i;
            }
        }

        // If N becomes a prime greater than 2
        if (N > 2) {
            largestFactor = N;
        }

        return largestFactor;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends