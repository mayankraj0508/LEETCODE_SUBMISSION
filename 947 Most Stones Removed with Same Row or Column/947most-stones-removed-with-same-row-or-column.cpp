class Solution {
public: 
    unordered_set<int> visited;
    unordered_set<int> node;

    void dfs(int src, vector<vector<int>>& graph) {
        visited.insert(src);
        for (auto neighbour : graph[src]) {
            if (!visited.count(neighbour)) {
                dfs(neighbour, graph);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> graph(20005);  // fixed size

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + 10001;   // 🔥 OFFSET

            node.insert(row);
            node.insert(col);

            graph[row].push_back(col);
            graph[col].push_back(row);
        }

        int count = 0;
        for (auto x : node) {
            if (!visited.count(x)) {
                count++;
                dfs(x, graph);
            }
        }

        return stones.size() - count;
    }
};
