class Solution {
public:
    int find(int val){
        int mx = INT_MIN;
        int mn = INT_MAX;
        while(val){
            int rem = val%10;
            val = val/10;
            mx = max(mx,rem);
            mn = min(mn,rem);  
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int , int>m;
        int mx_range = 0;
        for(int i =0; i<nums.size(); i++){
            int mx = find(nums[i]);//range 
            mx_range  = max(mx_range,mx);
            m[mx] = m[mx]+nums[i];
        }
        return m[mx_range];
    }
};