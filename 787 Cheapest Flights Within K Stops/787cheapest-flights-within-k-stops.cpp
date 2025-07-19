class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    typedef pair<int, int> np;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<np>> graph(n);
        
        for(auto flight : flights){
            int s = flight[0];
            int d = flight[1];
            int wt = flight[2];
            graph[s].push_back({d, wt});
        }

      //  unordered_set<int> visited;
        unordered_map<int, int> m;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, src}});
        
        for(int i = 0; i < n; i++){
            m[i] = INT_MAX;
        }
        m[src] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int stops = curr.first;
            int curr_dist = curr.second.first;
            int curr_node = curr.second.second;

            if(stops > k) continue;
           // if(visited.find(curr_node) != visited.end()) continue;

          //  visited.insert(curr_node);

            for(auto neighbour : graph[curr_node]){
                int neigh_node = neighbour.first;
                int neigh_dist = neighbour.second;

                if( m[neigh_node] > neigh_dist + curr_dist){
                    m[neigh_node] = neigh_dist + curr_dist;
                    pq.push({stops + 1, {m[neigh_node], neigh_node}});
                }
            }
        }

        if(m[dst] == INT_MAX){
            return -1;
        }
        return m[dst];
    }
};