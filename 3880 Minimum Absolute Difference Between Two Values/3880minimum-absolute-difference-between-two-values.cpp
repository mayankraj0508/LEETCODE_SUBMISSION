class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> ones, twos;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 1) ones.push_back(i);
            if(nums[i] == 2) twos.push_back(i);
        }

        if(ones.empty() || twos.empty()) return -1;

        int i = 0, j = 0;
        int ans = INT_MAX;

        while(i < ones.size() && j < twos.size()){
            ans = min(ans, abs(ones[i] - twos[j]));

            if(ones[i] < twos[j]) i++;
            else j++;
        }

        return ans;
    }
};