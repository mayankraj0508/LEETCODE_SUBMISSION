class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int j = n;
        vector<int>ans(2*n);
        int k = 0;
        while(k<2*n){
            ans[k] = nums[i];
            ans[k+1] = nums[j];
            i++;
            j++;
            k = k+2;

        }
        return ans;
        
    }
};