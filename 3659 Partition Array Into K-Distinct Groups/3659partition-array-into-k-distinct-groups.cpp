class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        int div = n%k;
        int q = n/k;
         if(nums.size()<k){
             return false;
         }
        if(div!=0){
            return false;
        }
        
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            if(x.second>q){
                return false;
            }
        }
       

        return true;
        
        
    }
};