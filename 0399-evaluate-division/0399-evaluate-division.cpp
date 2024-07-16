class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        double graph[40][40];
        auto it = values.begin();

        for(int i=0;i<40;i++) {
            for(int j=0;j<40;j++) 
            graph[i][j] = -1;
        }

        for(auto eq: equations) {
            int indx1 = equationAsIndex(eq[0]);
            int indx2 = equationAsIndex(eq[1]);
            graph[indx1][indx2] = *it;
            graph[indx2][indx1] = 1.0/(*it);
            ++it;
        }

        int size = eqIndexMap.size();

        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) {
                for(int k=0;k<size;k++) {
                    if(graph[j][i] != -1 && graph[i][k] != -1)
                    graph[j][k] = max(graph[j][k], graph[j][i]*graph[i][k]);
                }
            }
        }

        vector<double> sol;

        for(auto query: queries) {
            int indx1 = eqIndexMap.count(query[0]) ? eqIndexMap[query[0]] : -1;
            int indx2 = eqIndexMap.count(query[1]) ? eqIndexMap[query[1]] : -1;

            if (indx1 == -1 || indx2 == -1)
            sol.push_back(-1.0);
            else
            sol.push_back(graph[indx1][indx2]);
        }

        return sol;
    }

private:

    int equationAsIndex(string s) {
        if(eqIndexMap.count(s)) {
            return eqIndexMap[s];
        }
        eqIndexMap[s] = eqIndexMap.size();
        return eqIndexMap[s];
    }

    unordered_map<string, int> eqIndexMap;
};