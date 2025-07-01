class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        int v = numcourses;
        vector<int>indegree(v,0);
        queue<int>q;
        unordered_set<int>visited;
        vector<vector<int>>graph(numcourses);
        for(int i =0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i =0; i<indegree.size();i++){
            if(indegree[i]==0){
               q.push(i);
               visited.insert(i);
            }
        }
        vector<int>ans;
        while(q.size()>0){
            auto curr = q.front();
            ans.push_back(curr);
            q.pop();
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
        return ans.size()==numcourses;
        
     

        
    }
};