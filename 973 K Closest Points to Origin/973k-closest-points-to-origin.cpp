class Solution {
public:
typedef pair<int,int>pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int r = points.size();
        int c= points[0].size();
        priority_queue<pi>pq;

        for(int i =0; i<r; i++){
            int dist = 0;
            for(int j =0; j<c; j++){
                 dist = dist + points[i][j]*points[i][j];

            }
              pair<int,int>p = {dist,i};
                pq.push(p);
                if(pq.size()>k){
                    pq.pop();
                }
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            ans.push_back(points[pq.top().second]);
            pq.pop();

        }
        return ans;

        
    }
};