class Solution {
public:
    #define pp pair<int,int>
    void  shortestpath(int src,vector<vector<pp>>&graph,int distancethreshold,vector<int>&ans){
    unordered_set<int> visited;
    unordered_map<int,int> m; 
    // node -> {distance, parent}
    int count = 0;
    // Min-heap: pair<distance, node>
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0,src});
    for(int i =0;i<graph.size();i++){
        m[i]= INT_MAX;
    }
    m[src] = 0;
    while(pq.size()>0){
        auto curr =pq.top();
        int node  = curr.second;
        int dist = curr.first;
        pq.pop();
        if(visited.find(node)!=visited.end()){
            continue;
        }
        else{
            visited.insert(node);
            for(auto neighbour:graph[node]){
                int neigh_node = neighbour.first;
                int neigh_dist = neighbour.second;
                if(visited.find(neigh_node)==visited.end()&&dist+neigh_dist<m[neigh_node]){
                    
                    m[neigh_node] = dist+neigh_dist;
                    pq.push({m[neigh_node],neigh_node});
                }
            }
        }

    }
    for(int i =0; i<graph.size();i++){
        if(i!=src){
            if(m[i]<=distancethreshold){
                count++;
            }

        }
    }
    ans[src] = count;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distancethreshold) {
        vector<vector<pp>>graph(n);
        for(int i =0; i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           graph[u].push_back({v,wt});
           graph[v].push_back({u,wt});
        }
        vector<int>ans(n);
        for(int i =0; i<n;i++){
            shortestpath(i,graph,distancethreshold,ans);
        }
        int finalans= INT_MAX;
        int finalidx = 0;
        for(int i =0; i<n; i++){
            if(ans[i]<=finalans){
                finalans = ans[i];
                finalidx = i;
            }
        }
        return finalidx;
     
        

        
    }
};