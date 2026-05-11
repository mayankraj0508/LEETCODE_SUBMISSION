class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i =0; i<nums.size(); i++){
             int x = nums[i];
             string p = to_string(x);
             for(int k =0; k<p.size(); k++){
                int n = p[k]-'0';
                ans.push_back(n);
             }

        }
        return ans;
        
    }
};