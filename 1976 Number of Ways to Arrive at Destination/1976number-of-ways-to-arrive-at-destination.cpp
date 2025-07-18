class Solution {
public:
    #define pp pair<long long, int>
    const int MOD = 1e9 + 7;

    int shortest(int src, vector<vector<pp>>& graph, int n) {
        unordered_set<int> visited;
        unordered_map<int, long long> m;
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (int i = 0; i < n; i++) {
            m[i] = LLONG_MAX;
        }
        m[src] = 0;
        pq.push({0, src});

        vector<int> ways(n, 0);
        ways[src] = 1;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int curr_node = curr.second;
            long long curr_dist = curr.first;

            if (curr_dist > m[curr_node]) continue;

            for (auto neighbour : graph[curr_node]) {
                int neigh_node = neighbour.first;
                long long neigh_dist = neighbour.second;
                long long new_dist = curr_dist + neigh_dist;

                if (new_dist < m[neigh_node]) {
                    m[neigh_node] = new_dist;
                    ways[neigh_node] = ways[curr_node];
                    pq.push({new_dist, neigh_node});
                } else if (new_dist == m[neigh_node]) {
                    ways[neigh_node] = (ways[neigh_node] + ways[curr_node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pp>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        return shortest(0, graph, n);
    }
};
