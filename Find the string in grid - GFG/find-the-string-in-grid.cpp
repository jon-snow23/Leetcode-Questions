//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result;
        
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        // Iterate through each cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == word[0]) {
                    // Check in all 8 directions
                    for (int dir = 0; dir < 8; ++dir) {
                        int newRow = i + dx[dir];
                        int newCol = j + dy[dir];
                        int k;
                        for (k = 1; k < word.size(); ++k) {
                            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != word[k]) {
                                break;
                            }
                            newRow += dx[dir];
                            newCol += dy[dir];
                        }
                        
                        // If the word is found
                        if (k == word.size()) {
                            result.push_back({i, j});
                            break;  // No need to check other directions
                        }
                    }
                }
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends