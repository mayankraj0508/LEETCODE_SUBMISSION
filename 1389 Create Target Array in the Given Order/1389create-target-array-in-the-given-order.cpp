class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sz = -1;
        for(int i =0; i<index.size(); i++){
            sz = max(sz,index[i]);
        }
        vector<int>target(nums.size(),-1);
        int mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int idx = index[i];
     
            if(target[idx]==-1){
                target[idx] = nums[i];  
                 mx = max(mx,index[i]); 
            }
            else{
                for(int i = mx+1; i>=idx+1; i--){
                    target[i] = target[i-1];

                }
                target[idx]= nums[i];
                mx = mx+1;
            }
            
        }
        return target;

        
    }
};