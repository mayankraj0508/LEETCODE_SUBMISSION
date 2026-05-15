class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n  = nums.size();
        int mx = INT_MIN;
        for(int i =0; i<n; i++){
            mx= max(nums[i],mx);
        }
        if(n!=mx+1){
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i =0; i<n; i++){
            if(i==n-1){
                if(nums[i]!=n-1){
                    return false;
                }
            }
            if(nums[i]!=i+1 && i!=n-1){
                return false;
            }
        }
        return true;
        
    }
};