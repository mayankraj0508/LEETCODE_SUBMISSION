class Solution {
public: 
    #define pp pair<int,int>
    int shortest(int n,int src,vector<vector<pp>>&graph){
        unordered_set<int>visited;
        unordered_map<int,int>m; //node dist
        priority_queue<pp,vector<pp>,greater<pp>>pq; //dist,node
        pq.push({0,src});
        for(int i=0; i<=n;i++){
            m[i] = INT_MAX;
        }
        m[src] = 0;
        while(pq.size()>0){
            auto curr = pq.top();
            pq.pop();
            int curr_node = curr.second;
            int curr_dist = curr.first;
            if(visited.find(curr_node)!=visited.end()) continue;
            else{
                visited.insert(curr_node);
                for(auto neighbour:graph[curr_node]){
                    int neigh_node = neighbour.first;
                    int neigh_dist = neighbour.second;
                    if(visited.find(neigh_node)==visited.end()&&neigh_dist+curr_dist<m[neigh_node]){
                       m[neigh_node] = neigh_dist + curr_dist;
                       pq.push({m[neigh_node],neigh_node}); 
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<=n; i++){
            
           ans = max(ans,m[i]);
        }
        if(ans==INT_MIN||ans==INT_MAX){
            return -1;
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pp>>graph(n+1);
        for(int i=0; i<times.size(); i++ ){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            graph[u].push_back({v,wt});
        }
        return shortest( n, k,graph);

    }
};