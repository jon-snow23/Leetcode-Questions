//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{
public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<bool> rowFlag(R, false);
        vector<bool> colFlag(C, false);

        // Traverse the matrix and set rowFlag and colFlag accordingly
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    rowFlag[i] = true;
                    colFlag[j] = true;
                }
            }
        }

        // Traverse the matrix again and modify cells based on rowFlag and colFlag
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (rowFlag[i] || colFlag[j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends