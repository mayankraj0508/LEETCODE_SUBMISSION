class Solution {
public: 
    void dfs(vector<vector<int>>&height,vector<vector<int>>&ocean,int i,int j){
        if(i>=height.size()||i<0||j>=height[0].size()||j<0){
            return ;
        }
        if(ocean[i][j]==1){
            return ;
        }
        ocean[i][j] = 1;
        int  dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k = 0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0&&nx<height.size()&&ny>=0&&ny<height[0].size()){
                if(height[nx][ny]>=height[i][j]){
                    dfs(height,ocean,nx,ny);
                }
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        vector<vector<int>>pacific(height.size(),vector<int>(height[0].size(),0));
        vector<vector<int>>atlantic(height.size(),vector<int>(height[0].size(),0));
        for(int i =0; i<height.size(); i++){
         //   pacific[i][0] = 1;
             dfs(height,pacific,i,0);
        }
          for(int i =0; i<height.size(); i++){
            //atlantic[i][height[0].size()-1] = 1;
             dfs(height,atlantic,i,height[0].size()-1);
        }
        for(int j =0; j<height[0].size(); j++){
          //    pacific[0][j] = 1;
              dfs(height,pacific,0,j);
        }
         for(int j =0; j<height[0].size(); j++){
          //    atlantic[height.size()-1][j] = 1;
              dfs(height,atlantic,height.size()-1,j);
        }
        vector<vector<int>>ans;
        for(int i =0; i<pacific.size(); i++){
            for(int j=0; j<pacific[0].size(); j++){
                int x = pacific[i][j] && atlantic[i][j];
                if(x==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};