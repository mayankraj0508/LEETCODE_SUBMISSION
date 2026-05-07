class Solution {
public:
    vector<int> minCost(vector<int>& nums,
                                  vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                closest[i] = 1;
            else if (i == n - 1)
                closest[i] = n - 2;
            else {
                int left = nums[i] - nums[i - 1];
                int right = nums[i + 1] - nums[i];
                if (left <= right)
                    closest[i] = i - 1;
                else
                    closest[i] = i + 1;
            }
        }
        vector<long long> preright(n, 0);

        for (int i = 0; i < n - 1; i++) {
            if (closest[i] == i + 1)
                preright[i + 1] = preright[i] + 1;
            else
                preright[i + 1] = preright[i] + (nums[i + 1] - nums[i]);
        }

        vector<long long> preleft(n, 0);

        for (int i = n - 1; i > 0; i--) {
            if (closest[i] == i - 1)
                preleft[i - 1] = preleft[i] + 1;
            else
                preleft[i - 1] = preleft[i] + (nums[i] - nums[i - 1]);
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l < r) {
                ans.push_back(preright[r] - preright[l]);
            } else {
                ans.push_back(preleft[r] - preleft[l]);
            }
        }
        return ans;
    }
};