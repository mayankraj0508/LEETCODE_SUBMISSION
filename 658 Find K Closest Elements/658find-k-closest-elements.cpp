class Solution {
public:
  typedef pair<int,int>pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      
        priority_queue<pi>pq;
        int n = arr.size();
        for(int i =0; i<n; i++){
            int diff = abs(arr[i]-x);
            pair<int,int>p = {diff,arr[i]};
            pq.push(p);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};