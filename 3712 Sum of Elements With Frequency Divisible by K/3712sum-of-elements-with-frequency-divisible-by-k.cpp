class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            if((x.second)%k==0){
                for(int i =0; i<x.second; i++){
                    ans =ans+x.first;
                }
            }
        }
        return ans;
        
        
    }
};