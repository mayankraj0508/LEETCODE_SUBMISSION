class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>revgraph(graph.size());
        vector<int>indegree(n);
        for(int i =0; i<n; i++){
            for(int j = 0; j<graph[i].size();j++){
                revgraph[graph[i][j]].push_back(i);
                indegree[i]++;

            }
        }
        unordered_set<int>visited;
        queue<int>q;
        for(int i=0; i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }
        vector<int>ans;
        while(q.size()>0){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neighbour:revgraph[curr]){
                if(visited.find(neighbour)==visited.end()){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
      

        
    }
};