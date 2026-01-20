class Solution {
public:
  #define pp pair<int,int>
  int m ;
  int n ;
         int dx[4] = {1,-1,0,0};
       int dy[4] = {0,0,1,-1};
  vector<vector<int>>visited;
  void dfs(int i,int j,vector<vector<int>>&grid){
    if(i>=m || i<0 ||j>=n || j<0){
        return ;
    }
    visited[i][j]=1;
    grid[i][j] = -1;
    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==0 && grid[nx][ny]==1 ){
            dfs(nx,ny,grid);
        }
    }


  }
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,queue<pp>&q){
       
        int dist = 0;
       // int ans = INT_MAX;
      
        while(q.size()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto curr  =q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
               
                for(int k = 0; k<4; k++){
                    int nx = r+dx[k];
                    int ny = c+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0){
                        if(grid[nx][ny]==0){
                            q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                        else if (grid[nx][ny]==-1){
                            vis[nx][ny] = 1;
                             return dist;
                        }
                    }
                }

            }
            dist++;
        }
        return dist;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
         n = grid[0].size(); 
         bool flag = false;
         visited.resize(m,vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    flag = true;
                    break;
                }
            }
             if(flag==true){
                    break;
                }
        }
        queue<pp>q;
              vector<vector<int>>vis(m,vector<int>(n,0));
         for(int  i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==1){
                    vis[i][j] =1;
                    q.push({i,j});
                }
            }
         }
          int ans = bfs(grid,vis,q);
           return ans;
        

    }
};