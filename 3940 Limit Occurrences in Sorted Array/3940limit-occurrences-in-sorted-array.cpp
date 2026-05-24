class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int i =0;
        vector<int>ans;
         while(i<nums.size()){
             int freq = m[nums[i]];
             if(freq<k){
                 while(freq--){
                     ans.push_back(nums[i]);
                 }
             }
             else{
                 int x = k;
                 while(x--){
                     ans.push_back(nums[i]);
                 }
             }
             i = i+m[nums[i]];
         }
        return ans;
        
    }
};