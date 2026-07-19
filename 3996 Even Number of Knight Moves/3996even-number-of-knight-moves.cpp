class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        vector<pair<int,int>> dir = {
            {-2,1},{-1,2},{1,2},{2,1},
            {2,-1},{1,-2},{-1,-2},{-2,-1}
        };

        queue<pair<int,int>> q;
        vector<vector<int>> dist(8, vector<int>(8, -1));

        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == target[0] && y == target[1]) {
                return dist[x][y] % 2 == 0;
            }

            for (auto &[dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};