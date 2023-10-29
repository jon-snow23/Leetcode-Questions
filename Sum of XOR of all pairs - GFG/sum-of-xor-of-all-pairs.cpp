//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    long long int sumXOR(int arr[], int n) {
        long long int result = 0; // Initialize result to 0
        
        // Traverse through each bit position
        for (int bit = 0; bit < 32; ++bit) {
            // Count the number of elements with the bit set at the current position
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (arr[i] & (1 << bit)) {
                    count++;
                }
            }
            
            // Calculate the sum for the current bit position
            long long int sum = (1LL << bit) * count * (n - count);
            result += sum; // Add the sum to the result
        }
        
        return result; // Return the final result
    }
};


//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends