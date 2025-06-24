class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i  = 0;
        int n = nums.size();
        vector<string>ans;
        while(i<n){
            long long a = nums[i];
            long long b = nums[i];
            while(i<n&&b==nums[i]){
                b++;
                i++;
            }
            if(a==nums[i-1]){
                string lund = to_string(a);

                ans.push_back(lund);
            }
            else{
                string x = to_string(nums[i-1]);
                string l = to_string(a);
                string ch = "->";
                string final = l + ch + x;
                ans.push_back(final);
            }
        }
        return ans;
        
    }
};