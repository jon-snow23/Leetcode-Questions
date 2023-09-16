//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
public:
    // Function to return a list containing the first n Fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        vector<long long> result;

        if (n <= 0)
            return result; // Return an empty list for n <= 0

        // Initialize the first two Fibonacci numbers.
        long long a = 1, b = 1;

        // Add the first two numbers to the result list.
        result.push_back(a);
        if (n > 1)
            result.push_back(b);

        // Generate the remaining Fibonacci numbers.
        for (int i = 2; i < n; i++)
        {
            long long next = a + b;
            result.push_back(next);
            a = b;
            b = next;
        }

        return result;
    }
};


//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends