class Solution {
public: 
    void dfs(vector<vector<int>>&rooms,int curr,unordered_set<int>&visited){
        visited.insert(curr);
        for(auto neighbour:rooms[curr]){
            if(visited.find(neighbour)==visited.end()){
                dfs(rooms,neighbour,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        dfs(rooms,0,visited);
        return visited.size()==rooms.size();
    }
};