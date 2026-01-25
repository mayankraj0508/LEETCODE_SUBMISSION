class Solution {
public:
    int m,n;
     int  dx[4] = {1,-1,0,0};
     int dy[4] = {0,0,1,-1};
     vector<int>parent;
     vector<int>size;
    int find(vector<int>&parent,int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]  = find(parent,parent[x]);
    }
    void unions(vector<int>&parent,vector<int>&size,int a,int b){
        a = find(parent,a);
        b  = find(parent,b);
        if(a==b) return ;
        if(size[a]>=size[b]){
            size[a] = size[a]+ size[b];
            parent[b] = a;
        }
        else{
            size[b] = size[b]+ size[a];
            parent[a] = b;
        }
    }
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&visited,int &rx, int &ry){
        visited[i][j] = 1;
        int curr = i*n+j;
        int base = rx*n+ry;

        unions (parent,size,curr,base);
        int  dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
         for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && visited[nx][ny]==0){
                dfs(grid,nx,ny,visited,rx,ry);
            }
         }
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n  = grid[0].size();
        parent.resize(m*n);
 
        size.resize(m*n, 0);

for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        int curr = i*n + j;
        parent[curr] = curr;
        if(grid[i][j] == 1)
            size[curr] = 1;
    }
}

           vector<vector<int>>visited(m,vector<int>(n,0));
           for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    dfs(grid,i,j,visited,i,j);
                }

            }
           }
           int ans = INT_MIN;
           for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int>siz;
                    for(int k =0; k<4; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0){
                            int curr = nx*n+ny;
                           int root = find(parent, curr);
                           siz.insert(root);

                        }

                    }
                         int sum = 1;
                        for(auto x : siz){
                          sum = sum+size[x];
                        }
                        ans = max(ans,sum);

                   
                }
            }
           }
           if(ans==INT_MIN){
            return m*n;
           }
           return ans;
        
    }
};