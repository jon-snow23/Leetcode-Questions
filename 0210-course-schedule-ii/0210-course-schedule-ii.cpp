class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencylist(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int source = prerequisites[i][1];
            int neighbour = prerequisites[i][0];
            adjacencylist[source].push_back(neighbour);
            inDegree[neighbour]++;
        }
        queue<int> sources;
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
                sources.push(i);
        }
        vector<int> topoSort;
        while (!sources.empty())
        {
            int source = sources.front();
            topoSort.push_back(source);
            sources.pop();
            for (int neighbour : adjacencylist[source])
            {
                inDegree[neighbour] -= 1;
                if (inDegree[neighbour] == 0)
                    sources.push(neighbour);
            }
        }
        // THERE IS A CYCLE
        if (topoSort.size() != numCourses)
            return {};
        return topoSort;
    }
};