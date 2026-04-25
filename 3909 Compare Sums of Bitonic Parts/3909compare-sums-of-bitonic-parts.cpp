class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int mx = INT_MIN;
        int idx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>mx){
                idx = i;
                mx = nums[i];
            }
        }
        long long  asc = 0;
        long long dsc = 0;
        for(int i =0; i<=idx; i++){
            asc = asc+nums[i];
        }
        for(int i = idx; i<nums.size(); i++){
            dsc= dsc+nums[i];
        }
        if(asc>dsc){
            return 0;
        }
        if(dsc>asc){
            return 1;
        }
        return -1;
        
        
    }
};