class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // edge cases
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // visited
        
        int dist = 1;
        
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == n-1 && y == n-1)
                    return dist;
                
                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n 
                        && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // mark visited
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};
