#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q; 

        for(auto &x : sources){
            int r = x[0], c = x[1], col = x[2];
            if(time[r][c] == INT_MAX){
                ans[r][c] = col;
                time[r][c] = 0;
                q.push({r, c});
            } else {
                ans[r][c] = max(ans[r][c], col);
            }
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> curr = q.front();
                q.pop();
                
                int r = curr.first;
                int c = curr.second;
                int currentColor = ans[r][c];
                int currentTime = time[r][c];

                for(int k=0; k<4; k++){
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(time[nr][nc] > currentTime + 1){
                            time[nr][nc] = currentTime + 1;
                            ans[nr][nc] = currentColor;
                            q.push({nr, nc});
                        }
                        else if(time[nr][nc] == currentTime + 1){
                            ans[nr][nc] = max(ans[nr][nc], currentColor);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};