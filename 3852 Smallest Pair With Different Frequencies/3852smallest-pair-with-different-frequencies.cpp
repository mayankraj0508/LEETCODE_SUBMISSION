class Solution {
public:
    #define pp pair<int,int>
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
     priority_queue<pp, vector<pp>, greater<pp>>pq;
     for(int i =0; i<n; i++){
         for(int j=0; j<n; j++){
             if(nums[i]<nums[j] && m[nums[i]]!=m[nums[j]]){
                 pq.push({nums[i],nums[j]});
             }
         }
     }
        if(pq.size()==0){
            return {-1,-1};
        }
        vector<int>ans;
        ans.push_back(pq.top().first);
        ans.push_back(pq.top().second);
        return ans;
        
        
        
    }
};