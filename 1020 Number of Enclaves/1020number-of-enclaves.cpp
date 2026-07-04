class Solution {
public:
  #define pp pair<int,int>
   int m;
   int n;
    vector<vector<bool>>visited;
    void dfs(vector<vector<int>>&nums,int i, int j){
        visited[i][j] = true;
        nums[i][j] = -1;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k=0; k<4; k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false && nums[nr][nc]==1){
                dfs(nums,nr,nc);     
            }
        }
      
    }
    int numEnclaves(vector<vector<int>>& nums) {
       
        int countone = 0;
        m = nums.size();
        n = nums[0].size();
        queue<pp>q;
         visited.resize(m,vector<bool>(n,false));
        for(int i  = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(nums[i][j]==1){
                    countone++;
                if(i==0){
                    q.push({i,j});
                }
                if(i==m-1){
                    q.push({i,j});
                }
                if(j==0){
                    q.push({i,j});
                }
                if(j==n-1){
                    q.push({i,j});
                }
                }    
            }
        }
        while(q.size()){
            int i= q.front().first;
            int j = q.front().second;
            q.pop();
            if(visited[i][j]==false){
            dfs(nums,i,j);
            }
        }
        int remove  = 0;
        for(int i=0; i<m; i++){
            for(int j= 0; j<n; j++){
                if(nums[i][j]==-1){
                    remove++;
                    nums[i][j] = 1;
                }
            }
        }
        return countone-remove;
    }
};