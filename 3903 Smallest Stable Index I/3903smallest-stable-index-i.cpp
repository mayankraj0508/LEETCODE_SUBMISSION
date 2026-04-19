class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>mn(n);
        vector<int>mx(n);
        int mun = INT_MAX;
        int mux =INT_MIN;
        for(int i =0; i<n; i++){
            mux = max(mux,nums[i]);
            mx[i]  = mux;
            
        }
           for(int i =n-1; i>=0; i--){
            mun = min(mun,nums[i]);
            mn[i]  = mun;
            
        }
        for(int i =0; i<n; i++){
            if(mx[i]-mn[i]<=k){
                return i;
            }
        }
        return -1;
        
    }
};