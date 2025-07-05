class Solution {
public:
    void dfs(unordered_set<int>&visited,int i,vector<vector<int>>&graph){
        visited.insert(i);
        for(auto neighbour:graph[i]){
            if(visited.find(neighbour)==visited.end()){
                visited.insert(i);
                dfs(visited,neighbour,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n  =  isconnected.size();
        vector<vector<int>>graph(n+1);
        for(int i =0; i<n;i++){
            for(int j= 0; j<isconnected[i].size();j++){
                if(isconnected[i][j]==1){
                graph[i+1].push_back(j+1);
                }
            }
        }
        int ans = 0;
        unordered_set<int>visited;;
        for(int i =1; i<=n; i++){
            if(visited.find(i)==visited.end()){
                ans++;
                dfs(visited,i,graph);
            }
        }
        return ans;
        
    }
};