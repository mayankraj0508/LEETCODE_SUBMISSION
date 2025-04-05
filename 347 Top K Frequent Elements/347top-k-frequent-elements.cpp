class Solution {
public:
typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        int n = arr.size();
        for(int i =0; i<n; i++){
            m[arr[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto x:m){
            int ele = x.first;
            int freq = x.second;
            pair<int,int>p = {freq,ele};
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
        return ans;



        
    }
};