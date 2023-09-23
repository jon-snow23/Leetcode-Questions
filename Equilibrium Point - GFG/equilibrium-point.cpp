//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int equilibriumPoint(long long a[], int n) {
        // Calculate the total sum of the array
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += a[i];
        }

        // Initialize variables to keep track of the sum before and after current position
        long long sumBefore = 0;
        long long sumAfter = totalSum;

        for (int i = 0; i < n; i++) {
            // Update sumAfter by subtracting the current element from it
            sumAfter -= a[i];
            
            // Check if the sum before and after are equal
            if (sumBefore== sumAfter) {
                // Return the 1-based index of the equilibrium point
                return i + 1;
            }
            
            // Update sumBefore by adding the current element to it
            sumBefore += a[i];
        }

        // If no equilibrium point is found, return -1
        return -1;
    }
};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends