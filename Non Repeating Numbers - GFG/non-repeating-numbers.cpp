//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
         int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }

        int setBit = xorResult & -xorResult; // Find the rightmost set bit in xorResult
        int num1 = 0, num2 = 0;

        for (int num : nums) {
            if (num & setBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {min(num1, num2), max(num1, num2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends