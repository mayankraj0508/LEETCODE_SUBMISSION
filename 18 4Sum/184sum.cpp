class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int x) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        int l = 0;
        while (l < n) {

            if (l != 0) {

                while (l < nums.size() && nums[l] == nums[l - 1]) {
                    l++;
                }
            }
            if (l >= nums.size()) {
                break;
            }

            i = l + 1;
            while (i < n) {
                if (i > l + 1 && nums[i] == nums[i - 1]) {
                    i++;
                    continue;
                }
                if (i >= nums.size()) {
                    break;
                }
                long long target = (long long)x - nums[l] - nums[i];
                int j = i + 1;
                int k = nums.size() - 1;
                while (j < k) {
                    if (nums[j] + nums[k] == target) {
                        ans.push_back({nums[l], nums[i], nums[j], nums[k]});
                        int prev1 = nums[j];
                        int prev2 = nums[k];
                        j++;
                        k--;
                        while (j < k && nums[j] == prev1) {
                            j++;
                        }
                        while (k > j && nums[k] == prev2) {
                            k--;
                        }

                    } else if (nums[j] + nums[k] < target) {
                        int prev = nums[j];
                        j++;
                        while (j < nums.size() && nums[j] == prev) {
                            j++;
                        }
                    } else {
                        int prev = nums[k];
                        k--;
                        while (k >= 0 && nums[k] == prev) {
                            k--;
                        }
                    }
                }
                i++;
            }
            l++;
        }
        return ans;
    }
};