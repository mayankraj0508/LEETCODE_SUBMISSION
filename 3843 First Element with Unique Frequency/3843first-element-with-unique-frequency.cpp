class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        unordered_map<int,int>uni;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        unordered_set<int>vis;
        for(auto x: m){
            uni[x.second]++;
        }
        for(int i=0; i<n; i++){
            int num = m[nums[i]];
            if(uni[num]==1){
                return nums[i];
            }
        }
        return -1;
        
    }
};