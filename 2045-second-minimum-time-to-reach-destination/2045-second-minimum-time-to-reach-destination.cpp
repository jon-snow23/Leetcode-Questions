struct State {
    int node;
    int time;
    int count;
    bool operator>(const State& other) const {
        return time > other.time;
    }
};

class Solution {
public:
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }


    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({1, 0, 0});


    vector<vector<int>> min_time(n + 1, vector<int>(2, INT_MAX));
    min_time[1][0] = 0;

    while (!pq.empty()) {
        auto [node, curr_time, count] = pq.top();
        pq.pop();

        for (int neighbor : graph[node]) {
            int new_time = curr_time;

            if ((curr_time / change) % 2 == 1) { 
                new_time = (curr_time / change + 1) * change;
            }
            new_time += time;

            if (new_time < min_time[neighbor][0]) {
                min_time[neighbor][1] = min_time[neighbor][0];
                min_time[neighbor][0] = new_time;
                pq.push({neighbor, new_time, count + 1});
            } else if (new_time > min_time[neighbor][0] && new_time < min_time[neighbor][1]) {
                min_time[neighbor][1] = new_time;
                pq.push({neighbor, new_time, count + 1});
            }
        }
    }

    return min_time[n][1];
}

};