class Solution {
public:
    vector<int> findOrder(int numcourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numcourses);
        vector<int>indegree(numcourses,0);
        queue<int>q;
        unordered_set<int>visited;
        for(int i =0; i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0; i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }
        vector<int>ans;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neighbour:graph[curr]){
                if(visited.find(neighbour)==visited.end()){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
        if(ans.size()<numcourses){
            return {};
        }
        return ans;

        
    }
};